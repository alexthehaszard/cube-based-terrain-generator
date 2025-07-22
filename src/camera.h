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
    /**
     * HandleKeyboardInput
     * @param deltaTime change in time since last frame
     * @return vector containing the change in position since last frame
     */
    glm::vec3 HandleKeyboardInput(float deltaTime);
    /**
     * HandleMouseInput
     * @param deltaTime change in time since last frame
     * @return vector containing change in rotation (radians) since the last frame. (x: left/right, y: up/down)
     */
    glm::vec2 HandleMouseInput(float deltaTime);

    glm::mat4 m_View = glm::mat4(1.0f);
    glm::mat4 m_Projection;
    glm::mat4 m_Model = glm::mat4(1.0f);
    glm::vec2 m_LastCursorPosition = glm::vec2(0.0f);

    glm::vec3 m_Position;
    glm::vec2 m_Rotation;

    float m_Fov = 80.0f;
    float m_Velocity = 10.0f;

    std::shared_ptr<Shader> m_pShader;
    std::shared_ptr<Window> m_pWindow;

    const glm::vec3 kUpVector = glm::vec3{0.0f, 1.0f, 0.0f};
    const glm::vec3 kForwardsVector = glm::vec3{1.0f, 0.0f, 0.0f};
    const float kUpDownRotationLimit = glm::radians(90.0f);
    const float kLeftRightRotationLimit = glm::radians(360.0f);
};