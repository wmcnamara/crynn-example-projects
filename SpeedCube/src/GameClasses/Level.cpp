#include "Level.h"
namespace SpeedCube
{
	Level::Level()
	{
		m_mesh = new Mesh(m_vertices, 30, nullptr, 0,  VertexAttribTexCoords);
		m_shader = new Shader("data/shaders/Standard.vert", "data/shaders/Standard.frag");
		m_texture = new Texture("data/assets/wall.jpg");
		m_renderer = new MeshRenderer(*m_mesh, *m_texture, *m_shader, GetMatrix());
	}

	Level::~Level()
	{
		delete m_mesh;
		delete m_shader;
		delete m_texture;
		delete m_renderer;
	}

	void Level::Update(double deltaTime)
	{
		if (Input::GetKey(KeyCode::SPACE)) {}
		//m_renderer->active = !m_renderer->active;
	}

	void Level::Start()
	{
		Translate(Vec3(0, -1, 0));
		Scale(Vec3(5.0, -1, 50.0));
		Rotate(Vec3(90.0f, 0.0f, 0.0f));
	}
}