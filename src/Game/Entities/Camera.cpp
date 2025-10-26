#include "Camera.hpp"

void CCamera::Create() {
    m_flFov = 45.0f;
    m_flNear = 0.1f;
    m_flFar = 100.0f;

    m_vecPosition = glm::vec3(0.0f, 0.0f, 10.0f);
    m_vecUp = glm::vec3(0.0, 1.0f, 0.0f);
    m_vecRight = glm::vec3(1.0f, 0.0f, 0.0f);
    m_vecTarget = glm::vec3(0.0f, 0.0f, 0.0f);

    m_matView = glm::lookAt(m_vecPosition, m_vecTarget, m_vecUp);
    m_matProjection = glm::perspective(glm::radians(m_flFov), m_flAspectRatio, m_flNear, m_flFar);
};

void CCamera::Update() {
    m_matView = glm::lookAt(m_vecPosition, m_vecTarget, m_vecUp);
    m_matProjection = glm::perspective(glm::radians(m_flFov), m_flAspectRatio, m_flNear, m_flFar);
}

void CCamera::Send(CShaderProgram* ShaderProgram) {
    ShaderProgram->BindProgram();
    glUniformMatrix4fv(ShaderProgram->GetUniformLoc("mat_Projection"), 1, GL_FALSE, glm::value_ptr(m_matProjection));
    glUniformMatrix4fv(ShaderProgram->GetUniformLoc("mat_View"), 1, GL_FALSE, glm::value_ptr(m_matView));
    ShaderProgram->UnbindProgram();
}
