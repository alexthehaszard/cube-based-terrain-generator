#include "cube.h"
#include "square.h"

Cube::Cube(const glm::vec3& coords, const glm::vec3& dimensions)
{
    m_pVertexList = std::make_shared<std::vector<float>>();
    std::unordered_map<std::string, std::array<glm::vec3, 4>> faceCoordsMap;
    faceCoordsMap["front"] = {{
        glm::vec3{0, 0, 0} + coords, 
        glm::vec3{dimensions.x, 0, 0} + coords,
        glm::vec3{dimensions.x, dimensions.y, 0} + coords, 
        glm::vec3{0, dimensions.y, 0} + coords
    }};
    faceCoordsMap["back"] = GetOppositeFace(faceCoordsMap["front"], dimensions.z, 2);

    faceCoordsMap["left"] = {{
        glm::vec3{0, 0, 0} + coords, 
        glm::vec3{0, 0, dimensions.z} + coords,
        glm::vec3{0, dimensions.y, dimensions.z} + coords, 
        glm::vec3{0, dimensions.y, 0} + coords
    }};
    faceCoordsMap["right"] = GetOppositeFace(faceCoordsMap["left"], dimensions.x, 0);

    faceCoordsMap["bottom"] = {{
        glm::vec3{0, 0, 0} + coords, 
        glm::vec3{dimensions.x, 0, 0} + coords,
        glm::vec3{dimensions.x, 0, dimensions.z} + coords, 
        glm::vec3{0, 0, dimensions.z} + coords
    }};
    faceCoordsMap["top"] = GetOppositeFace(faceCoordsMap["bottom"], dimensions.y, 1);

    std::array<glm::vec2, 4> texCoords = {{
        {0.0f,0.0f},{1.0f,0.0f},{1.0f,1.0f},{0.0f,1.0f}
    }};

    for (const auto& faceCoords : faceCoordsMap)
    {
        Square face(faceCoords.second, texCoords);
        std::shared_ptr<std::vector<float>> pFaceVertexList = face.GetVertexArray();
        m_pVertexList->insert(m_pVertexList->end(), pFaceVertexList->begin(), pFaceVertexList->end());
    }
}

Cube::~Cube()
{

}

std::array<glm::vec3, 4> Cube::GetOppositeFace(const std::array<glm::vec3, 4>& face, float distance, int index)
{
    std::array<glm::vec3, 4> result = face;
    for (int i = 0; i < result.size(); i++)
    {
        result[i][index] += distance;
    }
    return result;
}