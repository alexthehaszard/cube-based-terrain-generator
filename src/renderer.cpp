#include <vector>
#include <array>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

unsigned int Renderer::GenerateVertexArrayObject(std::vector<float>& vertices)
{
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO); 

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    return VAO;
}