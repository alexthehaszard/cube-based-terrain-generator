#include "stdafx.h"
#include "window.h"
#include "renderer.h"
#include "cube.h"
#include "camera.h"
#include "shader.h"

int main() 
{
    glm::vec3 cameraPos = {0,0.5,0};
    glm::vec3 cameraTarget = {0,0,0};
    // World objects
    std::unique_ptr<Window> pWindow = std::make_unique<Window>(640, 480);
    std::unique_ptr<Renderer> pRenderer = std::make_unique<Renderer>();
    std::shared_ptr<Shader> pStandardShader = std::make_shared<Shader>("shaders/basic.vert", "shaders/basic.frag");
    std::unique_ptr<Camera> pCamera = std::make_unique<Camera>(cameraPos, cameraTarget, pStandardShader);
    pCamera->SetFov(90.0f);

    // Terrain objects
    Cube cube1({-0.5,-0.5,-0.5}, {1,1,1});
    std::shared_ptr<std::vector<float>> cubeVertexArray = cube1.GetVertexArray();

    // Main loop
    while (!pWindow->IsClosed())
    {
        pCamera->UpdatePosition();
        cube1.UpdateVertexArray();

        auto VAO = pRenderer->GenerateVertexArrayObject(*cubeVertexArray);
        // Draw frame using standard shader
        pStandardShader->use();
        pWindow->DrawFrame(VAO, cubeVertexArray->size() / 3);
    }

    return 0;
}