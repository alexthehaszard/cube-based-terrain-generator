#include "cube.h"
#include "square.h"

/**
 * This is very much proof-of-concepty
 * kinda sucks the way i'm doing it
 * in the future would like to clean this up a lot.
 */
Cube::Cube(glm::vec3 coords, glm::vec3 dimensions)
{
    m_pVertexList = std::make_shared<std::vector<float>>();

    std::array<glm::vec3, 4> frontCoords = {{
        glm::vec3{0, 0, 0} + coords, 
        glm::vec3{dimensions.x, 0, 0} + coords,
        glm::vec3{dimensions.x, dimensions.y, 0} + coords, 
        glm::vec3{0, dimensions.y, 0} + coords
    }};
    std::array<glm::vec3, 4> backCoords = {{
        glm::vec3{0, 0, dimensions.z} + coords, 
        glm::vec3{dimensions.x, 0, dimensions.z} + coords,
        glm::vec3{dimensions.x, dimensions.y, dimensions.z} + coords, 
        glm::vec3{0, dimensions.y, dimensions.z} + coords
    }};

    std::array<glm::vec3, 4> leftCoords = {{
        glm::vec3{0, 0, 0} + coords, 
        glm::vec3{0, 0, dimensions.z} + coords,
        glm::vec3{0, dimensions.y, dimensions.z} + coords, 
        glm::vec3{0, dimensions.y, 0} + coords
    }};
    std::array<glm::vec3, 4> rightCoords = {{
        glm::vec3{dimensions.x, 0, 0} + coords, 
        glm::vec3{dimensions.x, 0, dimensions.z} + coords,
        glm::vec3{dimensions.x, dimensions.y, dimensions.z} + coords, 
        glm::vec3{dimensions.x, dimensions.y, 0} + coords
    }};

    std::array<glm::vec3, 4> bottomCoords = {{
        glm::vec3{0, 0, 0} + coords, 
        glm::vec3{dimensions.x, 0, 0} + coords,
        glm::vec3{dimensions.x, 0, dimensions.z} + coords, 
        glm::vec3{0, 0, dimensions.z} + coords
    }};
    std::array<glm::vec3, 4> topCoords = {{
        glm::vec3{0, dimensions.y, 0} + coords, 
        glm::vec3{dimensions.x, dimensions.y, 0} + coords,
        glm::vec3{dimensions.x, dimensions.y, dimensions.z} + coords, 
        glm::vec3{0, dimensions.y, dimensions.z} + coords
    }};

    std::array<glm::vec2, 4> texCoords = {{
        {0.0f,0.0f},{1.0f,0.0f},{1.0f,1.0f},{0.0f,1.0f}
    }};

    Square front(frontCoords, texCoords);
    Square back(backCoords, texCoords);
    Square left(leftCoords, texCoords);
    Square right(rightCoords, texCoords);
    Square bottom(bottomCoords, texCoords);
    Square top(topCoords, texCoords);
    std::shared_ptr<std::vector<float>> pFrontVertexList = front.GetVertexArray();
    std::shared_ptr<std::vector<float>> pBackVertexList = back.GetVertexArray();
    std::shared_ptr<std::vector<float>> pLeftVertexList = left.GetVertexArray();
    std::shared_ptr<std::vector<float>> pRightVertexList = right.GetVertexArray();
    std::shared_ptr<std::vector<float>> pBottomVertexList = bottom.GetVertexArray();
    std::shared_ptr<std::vector<float>> pTopVertexList = top.GetVertexArray();

    m_pVertexList->insert(m_pVertexList->end(), pFrontVertexList->begin(), pFrontVertexList->end());
    m_pVertexList->insert(m_pVertexList->end(), pBackVertexList->begin(), pBackVertexList->end());
    m_pVertexList->insert(m_pVertexList->end(), pLeftVertexList->begin(), pLeftVertexList->end());
    m_pVertexList->insert(m_pVertexList->end(), pRightVertexList->begin(), pRightVertexList->end());
    m_pVertexList->insert(m_pVertexList->end(), pBottomVertexList->begin(), pBottomVertexList->end());
    m_pVertexList->insert(m_pVertexList->end(), pTopVertexList->begin(), pTopVertexList->end());
}

Cube::~Cube()
{

}