#include "Debug.h"

// Instantiate singleton class
Debug Debug::m_IntroState;

void Debug::Init(GLFWwindow* window) { }
void Debug::Cleanup() { }
void Debug::Pause() { }

void Debug::Update(float &dt) 
{	
}

void Debug::Draw() 
{	
}

void Debug::PollEvents() 
{
}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


void Debug_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

void Debug_mouse_callback(GLFWwindow* window, double _xPos, double _yPos)
{
}

void Debug_mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
}

void Debug::Resume(GLFWwindow* window) 
{
	glfwSetKeyCallback        ( window, Debug_key_callback );
    glfwSetCursorPosCallback  ( window, Debug_mouse_callback );
    glfwSetMouseButtonCallback( window, Debug_mouse_button_callback );
}
