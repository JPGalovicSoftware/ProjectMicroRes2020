#include <Entropy/Graphics/Window.h>
#include <Entropy/Graphics/Framebuffer.h>
#include <Entropy/Graphics/Shader.h>
#include <Entropy/Graphics/Mesh.h>

#include <iostream>
#include <exception>

using namespace Entropy;

#ifdef _DEBUG
int main()
#else
int WinMain()
#endif // _DEBUG
{
	try
	{
		// Setup and Initalize Window
		Graphics::Window window("Project MicroRes 2020", 600, 600);
		window.setResolution(64, 64);
		window.setClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		// Setup framebuffer
		Graphics::FrameBuffer frameBuffer(64, 64);
		frameBuffer.setClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		Graphics::QuadMesh quad;

		// Load Shaders
		Graphics::Shader quadShader("Assets/Shaders/vFBShader.glsl", "Assets/Shaders/fFBShader.glsl");

		// GameLoop
		while (!window.getShouldClose())
		{
			// Input

			// Update

			// Render
			// Render Game Into Framebuffer (for scaling)
			frameBuffer.bind();
			frameBuffer.clear();

			// Render to Screen
			window.bind();
			window.clear();
			// Render Quad
			quad.Draw(quadShader, frameBuffer);

			// Finish Frame
			window.processEvents();
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