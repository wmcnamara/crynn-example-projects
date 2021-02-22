#include "Object.h"
namespace SpeedCube
{
	Object::Object(Mesh* mesh, Shader* shader, Texture* texture) : m_shader(shader), m_texture(texture), m_mesh(mesh)
	{
		m_renderer = new MeshRenderer(*m_mesh, *m_texture, *m_shader, GetMatrix()); //Pass the transform matrix from the Transform class
	}
}