#include "poly.h"

Poly::Poly(std::array<glm::vec3, 3> coords, std::array<glm::vec2, 3> texCoords)
{
    m_pVertexList = std::make_shared<std::vector<float>>();
    for (int i = 0; i < coords.size(); i++)
    {
        m_pVertexList->push_back(coords[i].x);
        m_pVertexList->push_back(coords[i].y);
        m_pVertexList->push_back(coords[i].z);
        m_pVertexList->push_back(texCoords[i].x);
        m_pVertexList->push_back(texCoords[i].y);
    }
}

Poly::~Poly()
{

}