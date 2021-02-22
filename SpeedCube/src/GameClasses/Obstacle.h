#pragma once
#include <Crynn.h>
#include "Game.h"
#include "Core/CrynnObject.h"
#include "Core/Scene.h"
#include <deque>

using namespace crynn;

namespace SpeedCube
{
	class Obstacle : public CrynnObject
	{
	public:
		Obstacle(Mesh* mesh, Shader* shader, Texture* texture);

		const AABB& GetBoundingBox() const { return boundingBox; }

		~Obstacle();
	private:
		void Update(double deltaTime) override;
		float movementSpeed = 12.0f;
		AABB boundingBox{ *this, vec3(1, 1, 1) };

		Mesh* m_mesh;
		Shader* m_shader;
		Texture* m_texture;
		std::unique_ptr<MeshRenderer> m_renderer;

		float timeToDestruction = 2.0f;
	};
}