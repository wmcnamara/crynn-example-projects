#include "Player.h"
namespace SpeedCube
{
	Player::Player()
	{
		m_mesh = std::make_unique<Mesh>(m_vertices, 180, nullptr, 0, false); //The compiler wants nullptr here, you cant use NULL or 0
		m_shader = std::make_unique<Shader>("data/shaders/Standard.vert", "data/shaders/Standard.frag");
		m_texture = std::make_unique<Texture>("data/assets/joecool.jpg");
		m_camera = std::make_unique<Camera>(vec3(0, 0, -3), Projection::Perspective);
		m_renderer = std::make_unique<MeshRenderer>(*m_mesh.get(), *m_texture.get(), *m_shader.get(), GetMatrix());
	}

	Player::~Player()
	{
	}

	void Player::Render()
	{
		glEnable(GL_DEPTH_TEST);
	}

	glm::mat4& Player::GetViewMatrix()
	{
		return m_camera->GetMatrix();
	}

	const AABB& Player::GetBoundingBox()
	{
		return boundingBox;
	}

	void Player::Update(double deltaTime)
	{
		if (Game::IsOver())
			return;

		if (Input::GetKeyDown(KeyCode::ESC))
			Application::Quit();

		if (Input::GetKeyDown(KeyCode::D) && posIndex < 1)
		{
			Translate(vec3(2, 0, 0));
			posIndex++;
		}

		if (Input::GetKeyDown(KeyCode::A) && posIndex > -1)
		{
			Translate(vec3(-2, 0, 0));
			posIndex--;
		}

		if (Input::GetKeyDown(KeyCode::G))
			SetPosition(vec3(0, 0, 0)); //Reset pos

		Render();
	}

	void Player::Start()
	{
		m_camera->Rotate(vec3(30.0f, 0, 0));
		m_camera->Translate(vec3(0, -1, -3));
	}
}