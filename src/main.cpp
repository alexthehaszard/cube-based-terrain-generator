#include "stdafx.h"
#include "window.h"
#include "renderer.h"
#include "cube.h"
#include "camera.h"
#include "shader.h"

int main() 
{
    glm::vec3 cameraPos = {0,0,-1.5f};
    // World objects
    std::shared_ptr<Window> pWindow = std::make_unique<Window>(640, 480);
    std::shared_ptr<Shader> pStandardShader = std::make_shared<Shader>("shaders/basic.vert", "shaders/basic.frag");
    std::unique_ptr<Renderer> pRenderer = std::make_unique<Renderer>();
    std::unique_ptr<Camera> pCamera = std::make_unique<Camera>(cameraPos, pStandardShader, pWindow);
    pCamera->SetFov(90.0f);

    double lastFrameTime = glfwGetTime();
    float deltaTime = 0;

    // Terrain objects
    Cube cube1({-0.5,-0.5,-0.5}, {1,1,1});
    std::shared_ptr<std::vector<float>> cubeVertexArray = cube1.GetVertexArray();

    // Main loop
    while (!pWindow->IsClosed())
    {
        pCamera->UpdatePosition(deltaTime);
        cube1.UpdateVertexArray();

        auto VAO = pRenderer->GenerateVertexArrayObject(*cubeVertexArray);
        // Draw frame using standard shader
        pStandardShader->use();
        pWindow->DrawFrame(VAO, cubeVertexArray->size() / 3);
    
        deltaTime = glfwGetTime() - lastFrameTime;
        lastFrameTime += deltaTime;

        if (pWindow->GetKey(GLFW_KEY_ESCAPE)) break;
    }

    return 0;
}