#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target, std::shared_ptr<Shader> pShader) :
    m_Position(position),
    m_Target(target),
    m_pShader(pShader)
{

}

Camera::~Camera()
{

}

void Camera::UpdatePosition()
{
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); 

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(m_Fov), 640.0f / 480.0f, 0.1f, 100.0f);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));  

    m_pShader->SetMat4("view", view);
    m_pShader->SetMat4("projection", projection);
    m_pShader->SetMat4("model", model);
}