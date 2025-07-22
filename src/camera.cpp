#include "camera.h"

Camera::Camera(glm::vec3 position, std::shared_ptr<Shader> pShader, std::shared_ptr<Window> pWindow) :
    m_pShader(pShader),
    m_pWindow(pWindow)
{
    m_Position = position;
    m_LastCursorPosition = m_pWindow->GetCursorPos();
}

Camera::~Camera()
{

}

void Camera::UpdatePosition(float deltaTime)
{
    glm::vec2 rotation = HandleMouseInput(deltaTime);
    m_Rotation += rotation;

    // If we reach the left/right limit (+-360dev), use remainder (%)
    m_Rotation.x = std::fmodf(m_Rotation.x, kLeftRightRotationLimit);
    // If we reach the up/down limit (+-90deg), clamp
    m_Rotation.y = std::clamp(m_Rotation.y, -kUpDownRotationLimit, kUpDownRotationLimit);

    glm::vec3 movement = HandleKeyboardInput(deltaTime);
    m_Position += movement;

    m_View = glm::mat4(1.0f);
    // Rotation AROUND the X axis (up and down)
    m_View = glm::rotate(m_View, m_Rotation.y, kForwardsVector);
    // Rotation AROUND the Y axis (left and right)
    m_View = glm::rotate(m_View, m_Rotation.x, kUpVector);
    m_View = glm::translate(m_View, m_Position);

    m_Projection = glm::perspective(glm::radians(m_Fov), 640.0f / 480.0f, 0.1f, 100.0f);

    m_pShader->SetMat4("view", m_View);
    m_pShader->SetMat4("projection", m_Projection);
    m_pShader->SetMat4("model", m_Model);
}

glm::vec3 Camera::HandleKeyboardInput(float deltaTime)
{
    float distanceMoved = m_Velocity * deltaTime;
    float x = distanceMoved * sin(-m_Rotation.x);
    float z = distanceMoved * cos(-m_Rotation.x);
    glm::vec3 movement = glm::vec3(0.0f);

    if (m_pWindow->GetKey(GLFW_KEY_W) == GLFW_PRESS)
    {
        movement.x += x;
        movement.z += z;
    }
    if (m_pWindow->GetKey(GLFW_KEY_S) == GLFW_PRESS)
    {
        movement.x -= x;
        movement.z -= z;
    }

    if (m_pWindow->GetKey(GLFW_KEY_A) == GLFW_PRESS)
    {
        movement.x += z;
        movement.z -= x;
    }
    if (m_pWindow->GetKey(GLFW_KEY_D) == GLFW_PRESS)
    {
        movement.x -= z;
        movement.z += x;
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
    glm::vec2 result = m_LastCursorPosition - cursorPos;
    m_LastCursorPosition = cursorPos;
    return -glm::radians(result);
}