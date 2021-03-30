#include "Player.h"
namespace SpeedCube
{
	Player::Player()
	{
		//load model async
		std::future<STLDataPtr> future = std::async(std::launch::async, STLParser::Load, "data/models/Cube.stl");
		
		//do other loading		
		m_camera = std::make_unique<Camera>(Vec3(0, 0, -3), Projection::Perspective);
		m_shader = std::make_unique<Shader>("data/shaders/Standard.vert", "data/shaders/Standard.frag");
		m_texture = std::make_unique<Texture>("data/assets/joecool.jpg");

		STLDataPtr data = future.get();

		m_mesh = std::make_unique<Mesh>(data->GetVertices(), data->VertexCount(), nullptr, 0, VertexAttribNone); //The compiler wants nullptr here, you cant use NULL or 0
		m_renderer = std::make_unique<MeshRenderer>(*m_mesh.get(), *m_texture.get(), *m_shader.get(), GetMatrix());

	}

	Player::~Player()
	{
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
			Translate(Vec3(2, 0, 0));
			posIndex++;
		}

		if (Input::GetKeyDown(KeyCode::A) && posIndex > -1)
		{
			Translate(Vec3(-2, 0, 0));
			posIndex--;
		}

		if (Input::GetKeyDown(KeyCode::G))
			SetPosition(Vec3(0, 0, 0)); //Reset pos
	}

	void Player::BeforeUpdate(double deltaTime)
	{
		Shader::SetVec3Current("lightPos", GetPosition());
	}

	void Player::Start()
	{
		m_camera->Rotate(Vec3(30.0f, 0, 0));
		m_camera->Translate(Vec3(0, -1, -3));
	}
}