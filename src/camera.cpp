#include "camera.h"

Camera::Camera(glm::vec3 position, std::shared_ptr<Shader> pShader, std::shared_ptr<Window> pWindow) :
    m_pShader(pShader),
    m_pWindow(pWindow)
{
    m_View = glm::translate(m_View, position); 
}

Camera::~Camera()
{

}

void Camera::UpdatePosition(float deltaTime)
{
    glm::vec3 movement = HandleKeyboardInput(deltaTime);

    m_View = glm::translate(m_View, movement);
    m_Projection = glm::perspective(glm::radians(m_Fov), 640.0f / 480.0f, 0.1f, 100.0f);

    m_pShader->SetMat4("view", m_View);
    m_pShader->SetMat4("projection", m_Projection);
    m_pShader->SetMat4("model", m_Model);
}

glm::vec3 Camera::HandleKeyboardInput(float deltaTime)
{
    float distanceMoved = m_Velocity * deltaTime;
    glm::vec3 movement{0, 0, 0};

    if (m_pWindow->GetKey(GLFW_KEY_W) == GLFW_PRESS)
    {
        movement.z += distanceMoved;
    }
    if (m_pWindow->GetKey(GLFW_KEY_S) == GLFW_PRESS)
    {
        movement.z -= distanceMoved;
    }

    if (m_pWindow->GetKey(GLFW_KEY_A) == GLFW_PRESS)
    {
        movement.x += distanceMoved;
    }
    if (m_pWindow->GetKey(GLFW_KEY_D) == GLFW_PRESS)
    {
        movement.x -= distanceMoved;
    }

    if (m_pWindow->GetKey(GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        movement.y -= distanceMoved;
    }
    if (m_pWindow->GetKey(GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        movement.y += distanceMoved;
    }
    return movement;
}

glm::vec2 Camera::HandleMouseInput(float deltaTime)
{
    glm::vec2 cursorPos = m_pWindow->GetCursorPos();
    m_LastCursorPosition = cursorPos;
    return cursorPos;
}