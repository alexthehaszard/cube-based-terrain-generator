#include <stdafx.h>

#include "shader.h"
#include "window.h"

class Camera
{
public:
    Camera(glm::vec3 position, std::shared_ptr<Shader> pShader, std::shared_ptr<Window> pWindow);
    ~Camera();

    void UpdatePosition(float deltaTime);
    void SetFov(float fov) { m_Fov = fov; }
private:
    glm::vec3 HandleKeyboardInput(float deltaTime);
    glm::vec2 HandleMouseInput(float deltaTime);

    glm::mat4 m_View = glm::mat4(1.0f);
    glm::mat4 m_Projection;
    glm::mat4 m_Model = glm::mat4(1.0f);
    glm::vec2 m_LastCursorPosition = glm::vec2(0.0f);

    float m_Fov = 80.0f;
    float m_Velocity = 10.0f;

    std::shared_ptr<Shader> m_pShader;
    std::shared_ptr<Window> m_pWindow;
};