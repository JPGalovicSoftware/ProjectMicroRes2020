#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Framebuffer.h>
#include <Entropy/Graphics/Shader.h>
#include <Entropy/Graphics/Mesh.h>

#include <irrKlang.h>

#include <iostream>
#include <exception>

#include "StateCredits.h"
#include "StateGame.h"
#include "StateGameOver.h"
#include "StateMenu.h"
#include "StatePause.h"
#include "StateIntro.h"
#include "StateVictory.h"

//#include "AudioEngine.h"

#include "ResourceManager.h"
#include "EntityManager.h"

using namespace Entropy;

#ifdef _DEBUG
int main()
#else
int WinMain()
#endif // _DEBUG
{
	try
	{
		// Initalize Audio Engine
		//AudioEngine audioEngine;

		// Setup and Initalize Window
		Graphics::Window window("I Just Wanna Grill!", 600, 600, 1);
		window.setResolution(64, 64);
		window.setClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		window.setIcon(Graphics::LoadTexture::LoadImage("Assets/icon.png"));

		// Setup framebuffer
		Graphics::FrameBuffer frameBuffer(64, 64);
		frameBuffer.setClearColor(0.1f, 0.1f, 0.1f, 0.1f); // Set to transparent clearing color
		Graphics::QuadMesh quad;

		// Load Resources
		ResourceManager::loadData("Assets/asset_directory.csv");

		// Load Game States
		StateCredits credits = StateCredits();
		StateGame game = StateGame();
		StateGameOver gameOver = StateGameOver();
		StateMenu menu = StateMenu();
		StatePause pause = StatePause();
		StateIntro intro = StateIntro();
		StateVictory victory = StateVictory();

		// Connect Game States
		credits.addConnection(0, &menu);
		game.addConnection(0, &pause);
		game.addConnection(1, &gameOver);
		game.addConnection(2, &victory);
		gameOver.addConnection(0, &menu);
		menu.addConnection(0, &game);
		menu.addConnection(1, &credits);
		pause.addConnection(0, &game);
		pause.addConnection(1, &menu);
		intro.addConnection(0, &menu);
		victory.addConnection(0, &menu);

		// Initialise States & State Engine
		credits.init();
		game.init();
		gameOver.init();
		menu.init();
		pause.init();
		intro.init();
		victory.init();

		GameState * gameState = &intro;

		// GameLoop
		while (!window.getShouldClose())
		{
			// Input
			gameState->input(window);

			// Update
			gameState = gameState->update(gameState);

			// Render
			// Render Game Into Framebuffer (for scaling)
			frameBuffer.bind();
			frameBuffer.clear();

			gameState->render();

			// Render to Screen
			window.bind();
			window.clear();
			// Render Quad
			quad.Draw(ResourceManager::getShader("quadShader"), frameBuffer);

			// Finish Frame
			window.processEvents();
			ResourceManager::pollClock();
		}

		return 0;
	}
	catch (std::exception e)
	{
		// Handle Exeptions
		std::cout << e.what() << std::endl;
		return -1;
	}
	
}