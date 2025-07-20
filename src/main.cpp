#include "stdafx.h"
#include "window.h"
#include "renderer.h"
#include "cube.h"
#include "camera.h"

int main() 
{
    glm::vec3 cameraPos = {0,1,0};
    glm::vec3 cameraTarget = {0,0,0};
    // World objects
    std::unique_ptr<Window> pWindow = std::make_unique<Window>(640, 480);
    std::unique_ptr<Renderer> pRenderer = std::make_unique<Renderer>();
    std::unique_ptr<Camera> pCamera = std::make_unique<Camera>(cameraPos, cameraTarget);
    pCamera->SetFov(90.0f);

    // Terrain objects
    Cube cube1({-0.5,-0.5,-0.5}, {1,1,1});
    std::shared_ptr<std::vector<float>> cubeVertexArray = cube1.GetVertexArray();

    unsigned int shaderProgram = pWindow->SetupShaders();

    // Main loop
    while (!pWindow->IsClosed())
    {
        pCamera->UpdatePosition(shaderProgram);
        cube1.UpdateVertexArray();

        auto VAO = pRenderer->GenerateVertexArrayObject(*cubeVertexArray);
        pWindow->DrawFrame(shaderProgram, VAO, cubeVertexArray->size() / 3);
    }

    return 0;
}