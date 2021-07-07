#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "App.h"

#include "openGLutils.h"

namespace CueEngine
{
    class GameState;
    class Engine
    {
    public:
        Engine(int xMax, int yMax, char* windowTitle);
        ~Engine();

        void PushState(GameState* state);
        void PopState();        

        void Update(float &dt);
        void Draw();
        void PollEvents();

        bool ToClose() { return glfwWindowShouldClose(m_window); }

    private:
        GLFWwindow *m_window;
        std::vector<GameState*> m_states;

        int m_xMax, m_yMax;
    };
} // End namespace CueEngine