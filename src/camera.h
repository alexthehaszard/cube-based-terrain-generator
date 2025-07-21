#include <stdafx.h>

#include "shader.h"

class Camera
{
public:
    Camera(glm::vec3 position, glm::vec3 target, std::shared_ptr<Shader> pShader);
    ~Camera();

    void UpdatePosition();
    void SetFov(float fov) { m_Fov = fov; }
private:
    glm::vec3 m_Position;
    glm::vec3 m_Target;
    float m_Fov = 80.0f;

    std::shared_ptr<Shader> m_pShader;
};