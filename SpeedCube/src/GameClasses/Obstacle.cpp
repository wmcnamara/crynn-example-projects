#include "Obstacle.h"
namespace SpeedCube
{
	Obstacle::Obstacle(Mesh* mesh, Shader* shader, Texture* texture) : m_mesh(mesh), m_shader(shader), m_texture(texture)
	{
		m_renderer = std::make_unique<MeshRenderer>(*m_mesh, *m_texture, *m_shader, GetMatrix());
	}

	Obstacle::~Obstacle()
	{
	}

	void Obstacle::Update(double deltaTime)
	{
		if (!Game::IsOver())
		{
			Translate(Vec3(0, 0, deltaTime * movementSpeed));

			timeToDestruction -= deltaTime;
			if (timeToDestruction <= 0.0f)
			{
				Scene::RemoveObject(GetID());
				timeToDestruction = 2.0f;
			}
		}
	}
}