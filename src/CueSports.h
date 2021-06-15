#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "openGLutils.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>

#include "linear.h"

enum class CueGameType { cueWorldRules, 
                         cue8BallPool, 
                         cueCarrom, 
                         cueBilliards, 
                         cueSnooker, 
                         cueDebug };

class CueGame
{
private:
    // Type of cue sport type
    CueGameType m_GameType;

    // Internal positions 
    vect2f m_cueBallPos;
    std::vector<vect2f> m_objectsA;
    std::vector<vect2f> m_objectsB;
    std::vector<vect2f> m_trianglesA;
    std::vector<vect2f> m_trianglesB;

    float m_ballRadius; // Ball radii
    int m_NSides;       // number of edges forming 'circle'
    
    // OpenGl buffers
    GLuint m_VBobjectsA;
    GLuint m_VBobjectsB;

    // Shader object
    Shader m_shader;

    void BuildVB();

public:
    CueGame()
    : m_GameType( CueGameType::cueDebug ),
      m_cueBallPos( {-0.5, 0.5} ),
      m_ballRadius( 0.07 ),
      m_NSides(8*18),
      m_shader( Shader("shaders/Basic.shader") )
    { 
        // Initialise the vertex buffer objects
        for(auto i : { m_VBobjectsA, m_VBobjectsB })
        {
            glGenBuffers(1, &i);
            glBindBuffer(GL_ARRAY_BUFFER, i);
        }

        // Add one ball in each object ball category.
        m_objectsA.push_back( { -0.5,  0.5 } );
        m_objectsB.push_back( { 0.5, -0.5 } );

        BuildVB();
    }
    CueGame(CueGameType _gameType);
    ~CueGame();

    void Draw();
    void ComputeVB();
};
