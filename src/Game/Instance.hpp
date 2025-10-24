#pragma once

#include "Layout.hpp"
#include "Shader.hpp"
#include "Buffer.hpp"
#include "Model_Loader.hpp"
#include "glm/glm.hpp"
#include "glm/ext.hpp"

//-----------------------------------------------------------------------------
// Purpose: A Contract for every drawable and non-drawable objects
//-----------------------------------------------------------------------------
class IBase3D {
protected:
    glm::vec3 m_vecPosition;
    glm::mat4 m_matPosition;
};

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


//-----------------------------------------------------------------------------
// Purpose: Drawable object's class interface
//-----------------------------------------------------------------------------
class IInstance3D : public IBase3D {
protected:
    CLayout m_VertexArray;
    Buffer m_VertexBuffer, m_ElementBuffer;

    CShader m_Fragment, m_Vertex;
    CShaderProgram m_Program;
public:
    virtual void Create() = 0;
    virtual void Draw(void) = 0;
    virtual void Update() {};
    virtual ~IInstance3D() = default;
};

class CCube : public IInstance3D {
private:
    std::vector<glm::vec3>* m_vecModelVertices;
    std::vector<unsigned int>* m_vecModelIndices;
    CModel_Loader m_Loader;
public:
    void Create() override;
    void Draw(void) override;
};

class CCamera : public CBaseCamera {
public:
    void Create() override;
};
