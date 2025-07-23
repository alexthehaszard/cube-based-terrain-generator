#include "stdafx.h"
#include "window.h"
#include "renderer.h"
#include "shapes/cube.h"
#include "shapes/square.h"
#include "shapes/poly.h"
#include "camera.h"
#include "shader.h"

int main() 
{
    glm::vec3 cameraPos = {0,0,0};
    // World objects
    std::shared_ptr<Window> pWindow = std::make_unique<Window>(640, 480);
    std::shared_ptr<Shader> pStandardShader = std::make_shared<Shader>("shaders/basic.vert", "shaders/basic.frag");
    std::unique_ptr<Renderer> pRenderer = std::make_unique<Renderer>();
    std::unique_ptr<Camera> pCamera = std::make_unique<Camera>(cameraPos, pStandardShader, pWindow);
    pCamera->SetFov(90.0f);

    double lastFrameTime = glfwGetTime();
    float deltaTime = 0;

    // Terrain objects
    Cube cube1({0,1,0}, {1,1,1});
    Cube cube2({1,-2,0}, {1,1,1});
    pRenderer->AddObject(cube1);
    pRenderer->AddObject(cube2);

    unsigned int wallTexture = pRenderer->LoadTextureFromFile("images/wall.jpg");

    // Main loop
    while (!pWindow->IsClosed())
    {
        pCamera->UpdatePosition(deltaTime);

        // Draw frame using standard shader
        pStandardShader->use();
        pWindow->DrawFrame(
            pRenderer->GenerateVertexArrayObject(),
            pRenderer->GetPolyCount(),
            wallTexture);
    
        deltaTime = glfwGetTime() - lastFrameTime;
        lastFrameTime += deltaTime;

        if (pWindow->GetKey(GLFW_KEY_ESCAPE)) break;
    }

    return 0;
}