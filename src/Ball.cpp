#include "Ball.h"

glm::vec3 SphereToCart(float r, float theta, float phi, glm::vec2 offset)
{
    return { r * sin(theta) * cos(phi),
             r * sin(theta) * sin(phi),
             r * cos(theta) };
}

void PoolBall::InitBuffer()
{
    // First, construct the vertices on the sphere which represents the 
    // ball and which we will attach the texture to.

    int L = 40;

    int nThe = 100;
    int nPhi = 100;

    float dThe =   M_PI/nThe;
    float dPhi = 2*M_PI/nPhi;
    
    // Sphere:
    for (int i = 0; i < nThe; i++)
    {
        for (int j = 0; j < nPhi; j++)
        {
            float theta = i * dThe;
            float phi   = j * dPhi;

            float texTheta = theta/M_PI;
            float texPhi   = phi/(2*M_PI);

            float thetaP = (i+1) * dThe;
            float phiP   = (j+1) * dPhi;

            float texThetaP = thetaP/M_PI;
            float texPhiP   = phiP/(2*M_PI);

            glm::vec3 temp = glm::vec3(theta/3.141/2, phi, 0.);

            std::cout << texTheta << " " << texPhi << std::endl;

            std::vector<glm::vec3> triangle1[] = {
                { SphereToCart(radius, theta, phi, pos),  { texPhi, texTheta, 0.} },
                { SphereToCart(radius, theta, phiP, pos), { texPhiP, texTheta, 0.} },
                { SphereToCart(radius, thetaP, phi, pos), { texPhi, texThetaP, 0.} }
            };

            std::vector<glm::vec3> triangle2[] = {
                { SphereToCart(radius, theta, phiP, pos),  { texPhiP, texTheta,  0. } },
                { SphereToCart(radius, thetaP, phiP, pos), { texPhiP, texThetaP, 0.} },
                { SphereToCart(radius, thetaP, phi, pos),  { texPhi, texThetaP, 0. } }
            };

            for (int k = 0; k < 3; k++)
            {
                vertices.push_back(triangle1[k][0].x);
                vertices.push_back(triangle1[k][0].y);
                vertices.push_back(triangle1[k][0].z);
                vertices.push_back(triangle1[k][1].x);
                vertices.push_back(triangle1[k][1].y);

            }
            for (int k = 0; k < 3; k++)
            {
                vertices.push_back(triangle2[k][0].x);
                vertices.push_back(triangle2[k][0].y);
                vertices.push_back(triangle2[k][0].z);                
                vertices.push_back(triangle2[k][1].x);
                vertices.push_back(triangle2[k][1].y);
            }
        }
        
        glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), vertices.data(), GL_DYNAMIC_DRAW);
    }
}

void PoolBall::Draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Set translation 
    m_translation = glm::translate(glm::mat4(1.), glm::vec3(pos.x, pos.y, 0.));
    
    // Set rotation
    m_rotation = glm::rotate(glm::mat4(1.0f), m_theta - float(M_PI/2.), glm::vec3(0., 1., 0.));
    m_rotation = glm::rotate(glm::mat4(1.0f), m_phi + float(M_PI/2.), glm::vec3(0., 0., 1.)) * m_rotation;
    
    // Shader
    m_shader.SetUniform4mf("proj", m_projection * m_translation * m_rotation );
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}

void PoolBall::Update(float dt)
{
    m_phi += dt;
    m_theta += 2*dt;
}

void PoolBall::LoadTexture(std::string gameType)
{
    glBindTexture(GL_TEXTURE_2D, m_texture);


    std::string name;
    name = "textures/" + gameType + "/Ball" + std::to_string(number) + ".jpg";

    int width, height, nrChannels;
    unsigned char *data = stbi_load(name.data(), &width, &height, &nrChannels, 0); 
    
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Error reading data" << std::endl;
    }
}