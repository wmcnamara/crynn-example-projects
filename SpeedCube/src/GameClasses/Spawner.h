#pragma once
#include <Crynn.h>
#include "Obstacle.h"
#include "Core/CrynnObject.h"
#include "Player.h"
#include "Core/Scene.h"
#include "Game.h"
#include <array>
namespace SpeedCube
{
	/// <summary>
	/// The spawner works by instantiating two/one cubes in random lanes at a position in front of the player.
	/// </summary>
	class Spawner : protected GuiWindow
	{
	public:
		Spawner(Player* player);
		~Spawner();

		void Spawn();
		void RemoveSpawnedObjects();
	protected:
		float spawnRate = 0.50f;
		float spawnDistFromPlayer = -9;

		//This memory is pointed to by every obstacle that is spawned.
		Mesh* obstacleMesh;
		Shader* obstacleShader;
		Texture* obstacleTexture;

		void GUIDraw() override;
	private:
		Player* m_player;
        
        void Update(double deltaTime) override;
		void BeforeClose() override;

		//toggle spawning
		bool shouldSpawn = true;
	};
}