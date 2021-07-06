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

////////////////////////////////////////////////////////////////////////////
unsigned int widthX = 2000;
unsigned int widthY = 1000;
std::string title = "8Ball";
////////////////////////////////////////////////////////////////////////////

bool clicked = false;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

void mouse_callback(GLFWwindow* window, double _xPos, double _yPos)
{
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
}

int main(void)
{
	// Initialise GLFW window
	GLFWwindow* window;
	App::init( &window, widthX, widthY, title );
	glfwSetKeyCallback( window, key_callback );
	glfwSetCursorPosCallback( window, mouse_callback );
	glfwSetMouseButtonCallback( window, mouse_button_callback );
	glClearColor(10./255., 108./255., 3./255., 1.);

	vect2f vect = circle( { 0., 0.}, 1.0, 14, 14 );
	vect.print();

	PoolBall myBall(widthX, widthY, widthY/15.);

	//CueGame myGame(widthX, widthY);

	// Main loop with timer to track frame times
	App::Timer timer;
	float t = 0;
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		float dt = timer.dt();
		t += dt;

		// Update code goes here.
		//myGame.Draw();
		myBall.Draw();
		myBall.Update(dt);
		GLCall( glfwSwapBuffers(window) );
		GLCall( glfwPollEvents() );
	}
	
	return 0;
}
