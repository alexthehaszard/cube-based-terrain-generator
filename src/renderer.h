#include "stdafx.h"

#include "shapes/object.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    /**
     * Renderer::GenerateVertexArrayObject
     * @param vertices Array of vertices to add to the VAO
     * @return the generated Vertex Array Object (VAO)
     */
    unsigned int GenerateVertexArrayObject();

    /**
     * Renderer::LoadTextureFromFile
     * @param filepath Filepath to find the texture image file
     * @return the loaded texture
     */
    unsigned int LoadTextureFromFile(std::string filepath);

    unsigned int GetPolyCount();

    void AddObject(const Object& o);
private:
    std::vector<Object> m_Objects;
    std::vector<float> m_ObjectVertexList;
};