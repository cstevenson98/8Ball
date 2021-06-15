#include "CueSports.h"

CueGame::CueGame(CueGameType _gameType)
{

}

CueGame::~CueGame()
{
}

void CueGame::Draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VBobjectsA);
    glBufferData(GL_ARRAY_BUFFER, m_trianglesA.size()*sizeof(float), m_trianglesA.data(), GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, m_trianglesA.size());
}

void CueGame::BuildVB()
{
    // TODO: exceptions for length and so on.
    for(int i = 0; i < m_objectsA.size(); i++)
    {
        for (int j = 0; j < m_NSides; j++)
        {
            m_trianglesA.push_back(circle(m_objectsA[i], m_ballRadius, j, m_NSides));
            m_trianglesA.push_back(m_objectsA[i]);
            m_trianglesA.push_back(circle(m_objectsA[i], m_ballRadius, j+1, m_NSides));
        }
    }

    for(int i = 0; i < m_objectsB.size(); i++)
    {
        for (int j = 0; j < m_NSides; j++)
        {
            m_trianglesB.push_back(circle(m_objectsB[i], m_ballRadius, j, m_NSides));
            m_trianglesB.push_back(circle(m_objectsB[i], m_ballRadius, j+1, m_NSides));
            m_trianglesB.push_back(m_objectsB[i]);
        }
    }   

    m_trianglesA.insert(std::end(m_trianglesA), std::begin(m_trianglesB), std::end(m_trianglesB));

}