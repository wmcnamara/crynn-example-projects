#pragma once
#include <Crynn.h>
using namespace crynn;
namespace SpeedCube
{
	class Level : protected EventListener, protected Input, public Transform
	{
	public:
		Level();
		~Level();
	private:
		//Vertices to represent a plane
		float* m_vertices = new float[30]
		{
			-1.0f, -1.0f, -1.0f,  0.0f, 0.0f,
			1.0f, -1.0f, -1.0f,  1.0f, 0.0f,
			1.0f,  1.0f, -1.0f,  1.0f, 1.0f,
			1.0f,  1.0f, -1.0f,  1.0f, 1.0f,
			-1.0f,  1.0f, -1.0f,  0.0f, 1.0f,
			-1.0f, -1.0f, -1.0f,  0.0f, 0.0f,
		};

		Mesh* m_mesh;
		Shader* m_shader;
		Texture* m_texture;
		MeshRenderer* m_renderer;

		float speed = 0.1f;
		void Update(double deltaTime) override;
		void Start() override;
	};
}