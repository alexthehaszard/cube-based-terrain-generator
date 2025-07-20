#include <stdafx.h>

class Camera
{
public:
    Camera(glm::vec3 position, glm::vec3 target);
    ~Camera();

    void UpdatePosition(GLuint shaderProgram);
    void SetFov(float fov) { m_Fov = fov; }
private:
    glm::vec3 m_Position;
    glm::vec3 m_Target;
    float m_Fov = 80.0f;
};