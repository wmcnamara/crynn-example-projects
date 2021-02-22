#include <Crynn.h>
#include "GameClasses/Player.h"
#include "GameClasses/Level.h"
#include "GameClasses/Spawner.h"
#include "GameClasses/Game.h"
#include <thread>

using namespace crynn;
using namespace SpeedCube;

int main()
{
	Window window("SpeedCube", 1920, 1080);	
	Player player;	
	Level level;
	Game game;
	Spawner spawner(&player);

	Application::Initialise(); 	
	glClearColor(1.0, 1.0, 0.0, 1.0);

	while (!window.ShouldClose())
	{
		window.BeforeRender();
		Application::Tick();
		window.AfterRender();

		Scene::Clean();
	}
}