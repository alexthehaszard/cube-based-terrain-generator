#include "cube.h"

Cube::Cube(glm::vec3 coords, glm::vec3 dimensions) : 
    m_Coords(coords), 
    m_Dimensions(dimensions) 
{
    m_pVertexList = std::make_shared<std::vector<float>>();
}

Cube::~Cube()
{

}

std::shared_ptr<std::vector<float>> Cube::GetVertexArray()
{   
    return m_pVertexList;
}

void Cube::UpdateVertexArray()
{
    float x = m_Coords.x;
    float y = m_Coords.y;
    float z = m_Coords.z;

    float width = m_Dimensions[0];
    float height = m_Dimensions[1];
    float depth = m_Dimensions[2];

    m_pVertexList->assign({
        x,          y,          z,          // ----
        x + width,  y,          z,          // Bottom Left Front Face
        x,          y + height, z,          // ----

        x + width,  y,          z,          // ----
        x + width,  y + height, z,          // Top Right Front Face
        x,          y + height, z,          // ----


        x,          y,          z + depth,  // ----
        x + width,  y,          z + depth,  // Bottom Left Back Face
        x,          y + height, z + depth,  // ----

        x + width,  y,          z + depth,  // ----
        x + width,  y + height, z + depth,  // Top Right Back Face
        x,          y + height, z + depth,  // ----


        x,          y + height, z + depth,  // ----
        x,          y,          z + depth,  // Bottom Left Left Face
        x,          y,          z,          // ----

        x,          y + height, z + depth,  // ----
        x,          y + height, z,          // Top Right Left Face
        x,          y         , z,          // ----

        x + width,  y + height, z + depth,  // ----
        x + width,  y,          z + depth,  // Bottom Left Right Face
        x + width,  y,          z,          // ----

        x + width,  y + height, z + depth,  // ----
        x + width,  y + height, z,          // Top Right Right Face
        x + width,  y         , z,          // ----

        
        x,          y,          z,          // ----
        x,          y,          z + depth,  // Bottom Left Bottom Face
        x + width,  y,          z + depth,  // ----

        x,          y,          z,          // ----
        x + width,  y,          z,          // Top Right Bottom Face
        x + width,  y,          z + depth,  // ----

        x,          y + height, z,          // ----
        x,          y + height, z + depth,  // Bottom Left Top Face
        x + width,  y + height, z + depth,  // ----

        x,          y + height, z,          // ----
        x + width,  y + height, z,          // Top Right Top Face
        x + width,  y + height, z + depth,  // ----
    });
}