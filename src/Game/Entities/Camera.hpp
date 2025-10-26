#include "Core/Instance.hpp"

//-----------------------------------------------------------------------------
// Purpose: A Base class for every camera created
//-----------------------------------------------------------------------------
class CBaseCamera : public IBase3D {
protected:
    float m_flFov;
    float m_flAspectRatio;
    float m_flNear = 0.1, m_flFar = 100.0f;

    glm::mat4 m_matView;
    glm::mat4 m_matProjection;

    glm::vec3 m_vecUp;
    glm::vec3 m_vecRight;
    glm::vec3 m_vecTarget;
public:
    virtual void Create() {};
    virtual void Update() {};

    void SetAspectRatio(float flAspectRatio) {
        m_flAspectRatio = flAspectRatio;
    }

    float GetAspectRatio(void) const {
        return m_flAspectRatio;
    }

    const glm::mat4* GetViewMatrix(void) const {
        return &m_matView;
    }

    const glm::mat4* GetProjectionMatrix(void) const {
        return &m_matProjection;
    }
};

class CCamera : public CBaseCamera {
public:
    void Create() override;
    void Update() override;
    void Send(CShaderProgram* ShaderProgram);
    void SetAspectRatio(float flAspectRatio) {
        m_flAspectRatio = flAspectRatio;
    }
};
