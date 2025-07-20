#include "stdafx.h"

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
    unsigned int GenerateVertexArrayObject(std::vector<float>& vertices);
private:
};