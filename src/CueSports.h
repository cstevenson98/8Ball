#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "openGLutils.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>

#include "linear.h"
#include <glm/gtc/matrix_transform.hpp>

enum class CueGameType { cueWorldRules, 
                         cue8BallPool, 
                         cue3Cushion, 
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
    std::vector<float> m_trianglesA;
    std::vector<float> m_trianglesB;

    float m_ballRadius; // Ball radii
    int m_NSides;       // number of edges forming 'circle'
    
    // OpenGl buffers
    GLuint m_VBobjectsA;
    GLuint m_VBobjectsB;
    std::vector<float> m_AColor = { 0.8, 0.8, 0., 1. };
    std::vector<float> m_BColor = { 0.4, 0.0, 0., 1. };

    // Shader object
    Shader m_shader;

    // Matrix transformations
    glm::mat4 m_projection;


    void BuildVB();

public:
    CueGame(int xWidth, int yWidth)
    : m_GameType( CueGameType::cueDebug ),
      m_cueBallPos( {xWidth/2., yWidth/2.} ),
      m_ballRadius( 22. ),
      m_NSides( 8*18 ),
      m_shader( Shader("/home/conor/Dropbox/dev/8Ball/shaders/Basic.shader") )
    { 
        // Initialise the vertex buffer objects
        for(auto i : { m_VBobjectsA, m_VBobjectsB })
        {
            glGenBuffers(1, &i);
            glBindBuffer(GL_ARRAY_BUFFER, i);
        }

        // Add one ball in each object ball category.
        m_objectsA.push_back( {xWidth/2., yWidth/2.} );
        m_objectsA.push_back( {xWidth/3., yWidth/2.} );
        m_objectsB.push_back( {xWidth/4., yWidth/4.} );

        BuildVB();
        
        m_projection = glm::ortho(0., double(xWidth), 0., double(yWidth), -1., 1.);
        m_shader.SetUniform4mf("proj", m_projection);
    }
    CueGame(CueGameType _gameType);
    ~CueGame();

    void Update(float dt);
    void Draw();
    void ComputeVB();
};