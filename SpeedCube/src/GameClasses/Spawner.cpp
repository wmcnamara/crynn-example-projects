#include "Spawner.h"
namespace SpeedCube
{
	Spawner::Spawner(Player* player) : m_player(player), GuiWindow(ImVec2(300, 200), ImVec2(300, 300), "Spawner Configuration")
	{
		obstacleMesh = new Mesh(m_vertices, 180, NULL, 0, false);
		obstacleShader = new Shader("data/shaders/Obstacle.vert", "data/shaders/Obstacle.frag");
		obstacleTexture = new Texture("data/assets/perlinnoise.jpg");
		Spawn();
	}

	Spawner::~Spawner()
	{
		delete obstacleMesh;
		delete obstacleShader;
		delete obstacleTexture;
	}

	void Spawner::Spawn()
	{
		if (!shouldSpawn || Game::IsOver())
			return;

		ScopedTimer timer("Spawning", TimeFormat::Microseconds);

		//Remove old objects every other spawn
		static bool deleteOldObj = false;
		deleteOldObj = !deleteOldObj;

		//Get a random number for lane and object count
		int numOfObstacles = Random::Range(1, 2);
		for (int i = 0; i < numOfObstacles; i++)
		{
			int lane = Random::Range(-1, 1); //-1 = left, 1 = right

			//Create
			std::weak_ptr<Obstacle> obsPtr = Scene::CreateObject<Obstacle>(obstacleMesh, obstacleShader, obstacleTexture);
			std::shared_ptr<CrynnObject> obstacle = obsPtr.lock();

			//Set position
			//The player moves 2 units when changing lanes, so multiplying it by the lane index gives proper direction
			//Spawn objects at a distance in front the player
			obstacle->SetPosition(glm::vec3(lane * 2, 0, m_player->GetPosition().z + spawnDistFromPlayer));

			std::cout << "Spawning Object with ID: " << obstacle->GetID() << "\n";
		}
	}

	void Spawner::RemoveSpawnedObjects()
	{
		Scene::ClearObjects();
	}

	void Spawner::GUIDraw()
	{
#ifdef CRYNN_DEBUG
		ImGui::Begin("Spawner Configuration", &shouldSpawn, ImGuiWindowFlags_None);
		ImGui::Checkbox("Enable Spawning", &shouldSpawn);
		ImGui::End();
#endif
	}

	void Spawner::Update(double deltaTime)
	{
		//If the game is over, allow the player to restart the game.
		if (Input::GetKey(KeyCode::SPACE) && Game::IsOver())
		{
			//Restart game
			RemoveSpawnedObjects();
			Game::SetOverStateNoInvoke(false);
			return;
		}

#ifndef DISABLE_COLLISION
	    //Test collisions against the player on spawned objects
	    for (auto& [ID, obstacle] : Scene::GetManagedObjects()) 
		{
			if(AABB::Compare(m_player->GetBoundingBox(), dynamic_cast<const Obstacle&>(*obstacle).GetBoundingBox())) 
			{
				Game::Over();
				break;
			}

		}
#endif
		static double timer = spawnRate;
		timer -= deltaTime;

		if (timer <= 0)
		{
			Spawn();
			timer = spawnRate;
		}
	}

	void Spawner::BeforeClose()
	{
		std::cout << "BeforeClosed Invoked On Spawner" << std::endl;
		Scene::ClearObjects();
	}
}