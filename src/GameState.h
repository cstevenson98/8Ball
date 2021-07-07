#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GameEngine.h"

namespace CueEngine
{
    class GameState
    {
    private:
        /* data */
    public:
        virtual void Update(float &dt) = 0;
        virtual void Draw() = 0;
        virtual void PollEvents() = 0;

        virtual void Init(GLFWwindow* window) = 0;
        virtual void Cleanup() = 0;
        virtual void Pause() = 0;
        virtual void Resume(GLFWwindow* window) = 0;

        void PopState(Engine* game) { game->PopState(); }
        void PushState(Engine* game, GameState* state) { game->PushState(state); }

    protected:
        GameState() { }
    };
}