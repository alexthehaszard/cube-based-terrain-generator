#include <stdafx.h>

class Cube
{
public:
    Cube(glm::vec3 coords, glm::vec3 dimensions);
    ~Cube();

    std::shared_ptr<std::vector<float>> GetVertexArray();
    void UpdateVertexArray();
private:
    glm::vec3 m_Coords;
    glm::vec3 m_Dimensions;

    std::shared_ptr<std::vector<float>> m_pVertexList;
};