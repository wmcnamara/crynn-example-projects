#include <Crynn.h>
#include "GameClasses/Player.h"
#include "GameClasses/Level.h"
#include "GameClasses/Spawner.h"
#include "GameClasses/Game.h"
#include <thread>
#include "Utility/Parsers/STLParser.h"
#include "Core/Audio/Audio.h"

using namespace crynn;
using namespace SpeedCube;

int main()
{	
	Engine engine(800, 600, "SpeedCube");

	//Init stuff
	Player player;	

	Shader skyShader("data/shaders/Skybox.vert", "data/shaders/Skybox.frag");

	SkyboxFilePathData data(
	{		
		"data/assets/right.jpg",
		"data/assets/left.jpg",
		"data/assets/top.jpg",
		"data/assets/bottom.jpg",
		"data/assets/front.jpg",
		"data/assets/back.jpg", 
		skyShader 
	});

	Skybox skybox(data);

	Level level;
	Game game;
	Spawner spawner(&player);
	engine.Run();
}