#include "CueSports.h"

CueGame::CueGame(CueGameType _gameType)
{
}

CueGame::~CueGame()
{
}
void CueGame::Update(float dt)
{

}

void CueGame::Draw()
{
    // ToDo: write an update function that doesn't call sin/cos
    BuildVB();

    // A
    glBindBuffer(GL_ARRAY_BUFFER, m_VBobjectsA);
    glBufferData(GL_ARRAY_BUFFER, m_trianglesA.size()*sizeof(float), m_trianglesA.data(), GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    m_shader.SetUniform4f("u_Colour", m_AColor[0], m_AColor[1], m_AColor[2], m_AColor[3]);
    glDrawArrays(GL_TRIANGLES, 0, m_trianglesA.size());

    // B
    glBindBuffer(GL_ARRAY_BUFFER, m_VBobjectsB);
    glBufferData(GL_ARRAY_BUFFER, m_trianglesB.size()*sizeof(float), m_trianglesB.data(), GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    m_shader.SetUniform4f("u_Colour", m_BColor[0], m_BColor[1], m_BColor[2], m_BColor[3]);
    glDrawArrays(GL_TRIANGLES, 0, m_trianglesB.size());
}

void CueGame::BuildVB()
{
    // TODO: exceptions for length and so on.
    for(int i = 0; i < m_objectsA.size(); i++)
    {
        for (int j = 0; j < m_NSides; j++)
        {
            vect2f circJ = circle(m_objectsA[i], m_ballRadius, j, m_NSides);
            vect2f circJp1 = circle(m_objectsA[i], m_ballRadius, j+1, m_NSides);

            m_trianglesA.push_back(circJ.x);
            m_trianglesA.push_back(circJ.y);
            m_trianglesA.push_back(circJp1.x);
            m_trianglesA.push_back(circJp1.y);
            m_trianglesA.push_back(m_objectsA[i].x);
            m_trianglesA.push_back(m_objectsA[i].y);

        }
    }

    for(int i = 0; i < m_objectsB.size(); i++)
    {
        for (int j = 0; j < m_NSides; j++)
        {
            vect2f circJ = circle(m_objectsB[i], m_ballRadius, j, m_NSides);
            vect2f circJp1 = circle(m_objectsB[i], m_ballRadius, j+1, m_NSides);

            m_trianglesB.push_back(circJ.x);
            m_trianglesB.push_back(circJ.y);
            m_trianglesB.push_back(circJp1.x);
            m_trianglesB.push_back(circJp1.y);
            m_trianglesB.push_back(m_objectsB[i].x);
            m_trianglesB.push_back(m_objectsB[i].y);

        }
    }   

}