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
	Engine engine = Engine(800, 600, "SpeedCube");

	//Init stuff
	Player player;
	Level level;
	Game game;
	Spawner spawner(&player);
	
	engine.Run();
}