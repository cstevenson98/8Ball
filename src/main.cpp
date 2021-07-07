#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include <stdio.h>
#include <iostream>
#include <cassert>

#include <unordered_map>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>
#include <chrono>

#include "openGLutils.h"
#include "linear.h"
#include "App.h"
#include "CueSports.h"
#include "Ball.h"

#include "GameEngine.h"

////////////////////////////////////////////////////////////////////////////
int widthX = 2000;
int widthY = 1000;
char* title = "8Ball";
////////////////////////////////////////////////////////////////////////////

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
// {
// }

// void mouse_callback(GLFWwindow* window, double _xPos, double _yPos)
// {
// }

// void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
// {
// }

int main(void)
{

	CueEngine::Engine game(widthX, widthY, title);

	App::Timer timer;
	while (!game.ToClose())
	{
		float dt = timer.dt();
		game.Update(dt);
		game.Draw();
		game.PollEvents();
	}



	
	// Initialise GLFW window
	// GLFWwindow* window;
	// App::init( &window, widthX, widthY, title );
	// glfwSetKeyCallback( window, key_callback );
	// glfwSetCursorPosCallback( window, mouse_callback );
	// glfwSetMouseButtonCallback( window, mouse_button_callback );
	// glClearColor(10./255., 108./255., 3./255., 1.);

	// PoolBall myBall(widthX, widthY, widthY/15., 2);

	// //CueGame myGame(widthX, widthY);

	// // Main loop with timer to track frame times
	// App::Timer timer;
	// float t = 0;
	// while (!glfwWindowShouldClose(window))
	// {
	// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// 	float dt = timer.dt();
	// 	t += dt;

	// 	// Update code goes here.
	// 	//myGame.Draw();
	// 	myBall.Draw();
	// 	myBall.Update(dt);
	// 	GLCall( glfwSwapBuffers(window) );
	// 	GLCall( glfwPollEvents() );
	// }
	


	return 0;
}
