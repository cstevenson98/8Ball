#pragma once

#include "GameState.h"

class Debug : public CueEngine::GameState
{
public:
    void Update(float &dt);
    void Draw();
    void PollEvents();

    void Init(GLFWwindow* window);
    void Cleanup();
    void Pause();
    void Resume(GLFWwindow* window);

    static Debug* Instance() {
		return &m_IntroState;
	}

protected:
    Debug() { }

private:
	static Debug m_IntroState;
};
