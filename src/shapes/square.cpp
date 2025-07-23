#include "square.h"
#include "poly.h"

Square::Square(const std::array<glm::vec3, 4>& coords, const std::array<glm::vec2, 4>& texCoords)
{
    m_pVertexList = std::make_shared<std::vector<float>>();
    Poly poly1({coords[0], coords[1], coords[2]}, {texCoords[0], texCoords[1], texCoords[2]});
    Poly poly2({coords[0], coords[3], coords[2]}, {texCoords[0], texCoords[3], texCoords[2]});

    std::shared_ptr<std::vector<float>> pPoly1VertexList = poly1.GetVertexArray();
    std::shared_ptr<std::vector<float>> pPoly2VertexList = poly2.GetVertexArray();

    m_pVertexList->insert(m_pVertexList->end(), pPoly1VertexList->begin(), pPoly1VertexList->end());
    m_pVertexList->insert(m_pVertexList->end(), pPoly2VertexList->begin(), pPoly2VertexList->end());
}

Square::~Square()
{

}