#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h> 

#include "openGLutils.h"
#include "stb_image.h"

// Will contain all of the GL buffers and the ball motion. 

class PoolBall
{
private:
    glm::vec2 pos, vel;    
    float     m_theta, m_phi; 
    float     radius;
    int       number;

    /////////////////////////////////////

    GLuint VBO;             // VBO for Triangles 
    Shader m_shader;
    GLuint m_texture;
    glm::mat4 m_projection;
    glm::mat4 m_rotation;
    glm::mat4 m_translation;
    std::vector<float> vertices;

public:
    PoolBall(double xMax, double yMax, double _radius, int ballNum) 
    : pos      ( { xMax/2., yMax/2. } ),
      m_theta  ( 0. ),
      m_phi    ( 0. ),
      vel      ( {0., 0.} ),
      radius   ( _radius ),
      number   ( ballNum ),
      m_shader (Shader("shaders/PoolBall.shader")),
      m_projection (glm::ortho(0., xMax, 0., yMax, -_radius, _radius))
    {
        // Generate vertices and texture
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glGenTextures(1, &m_texture);

        LoadTexture(std::string("8Ball"));

        // Face culling 
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);  
        glFrontFace(GL_CCW);  

        // Form the vertices 
        InitBuffer();
    }

    /////////////////////////////////////

    ~PoolBall() 
    { 
        glDeleteBuffers(1, &VBO);
    }

    /////////////////////////////////////

    void InitBuffer();
    void LoadTexture(std::string GameType);
    void Update(float dt);
    void Draw();
};