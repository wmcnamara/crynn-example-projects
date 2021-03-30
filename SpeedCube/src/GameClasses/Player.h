#pragma once
#include "Crynn.h"
#include "Game.h"
#include "Utility/Parsers/STLParser.h"

using namespace crynn;

namespace SpeedCube
{
	class Player : protected EventListener, protected Input, public Transform
	{
	public:
		Player();
		~Player();

		glm::mat4& GetViewMatrix();

		const AABB& GetBoundingBox();
	private:
		std::unique_ptr<Mesh> m_mesh;
		std::unique_ptr<Shader> m_shader;
		std::unique_ptr<Texture> m_texture;
		std::unique_ptr<Camera> m_camera;
		std::unique_ptr<MeshRenderer> m_renderer;

		AABB boundingBox{ *this, Vec3(1, 1, 1) };
		int posIndex = 0; //0 = middle, 1 = left, 2 = right

		void Update(double deltaTime) override;
		void BeforeUpdate(double deltaTime) override;
		void Start() override;
	};


}