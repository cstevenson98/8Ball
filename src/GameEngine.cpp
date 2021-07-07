#include "GameEngine.h"
#include "Debug.h"

namespace CueEngine
{
    Engine::Engine(int xMax, int yMax, char* windowTitle)
        : m_xMax(xMax), m_yMax(yMax)
    {
        App::init( &m_window, m_xMax, m_yMax, windowTitle );
        glClearColor(10./255., 108./255., 3./255., 1.);

        PushState( Debug::Instance() );
    }

    Engine::~Engine()
    {
        glfwTerminate();
    }
        
    void Engine::PushState(GameState* state)
    {
        if ( !m_states.empty() )
        {
            m_states.back()->Pause();
        }

        m_states.push_back(state);
        m_states.back()->Init(m_window);
    }

    void Engine::PopState()
    {
        if ( !m_states.empty() )
        {
            m_states.back()->Cleanup();
            m_states.pop_back();
        }

        if ( !m_states.empty() )
        {
            m_states.back()->Resume(m_window);
        }
    }      

    void Engine::Update(float &dt)
    {
        m_states[0]->Update(dt);
    }

    void Engine::Draw()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        m_states[0]->Draw();

        GLCall( glfwSwapBuffers( m_window ) );
    }

    void Engine::PollEvents()
    {
        m_states[0]->PollEvents();
        GLCall( glfwPollEvents() );
    }
} // End namespace CueEngine