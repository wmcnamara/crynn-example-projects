#include "Game.h"
namespace SpeedCube
{
	bool Game::IsOver()
	{
		return over;
	}

	void Game::Over()
	{
		if (over)
			return;

		over = true;
		OnGameOver.Invoke();
		Debug::Log("Game Over");
	}

	void Game::Update(double deltaTime)
	{
		if (!over)
			return;

		ImVec2 widgetSize(210, 30);
		ImVec2 screenCenter = Window::GetSize() / 2;
		ImVec2 widgetCenter = widgetSize / 2;

		ImGui::SetNextWindowSize(widgetSize);
		ImGui::SetNextWindowPos(screenCenter - widgetCenter); //Center the text

		ImGui::Begin("GAME OVER", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
		ImGui::Text("PRESS SPACE FOR A NEW GAME!");
		ImGui::End();
	}
}