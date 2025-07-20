#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include "renderer.h"

std::vector<float> vertices = {
    // first triangle
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f,  0.5f, 0.0f,  // top left 
    // second triangle
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left
}; 

int main() 
{
    std::unique_ptr<Window> pWindow = std::make_unique<Window>(640, 480);
    std::unique_ptr<Renderer> pRenderer = std::make_unique<Renderer>();

    unsigned int shaderProgram = pWindow->SetupShaders();

    // Main loop
    while (!pWindow->IsClosed())
    {
        auto VAO = pRenderer->GenerateVertexArrayObject(vertices);
        pWindow->DrawFrame(shaderProgram, VAO, vertices.size() / 3);
    }

    return 0;
}