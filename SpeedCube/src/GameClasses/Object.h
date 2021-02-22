#pragma once
#include <Crynn.h>
using namespace crynn;
namespace SpeedCube
{
	class Object : protected EventListener, public Transform
	{
	public:
		Object(Mesh* mesh, Shader* shader, Texture* texture);
	private:
		Mesh* m_mesh;
		Shader* m_shader;
		Texture* m_texture;
		MeshRenderer* m_renderer;
	};
}
