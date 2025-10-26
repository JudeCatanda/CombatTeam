#pragma once

#include "Layout.hpp"
#include "Shader.hpp"
#include "Buffer.hpp"
#include "Model_Loader.hpp"
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include <glfw/glfw3.h>

//-----------------------------------------------------------------------------
// Purpose: A Contract for every drawable and non-drawable objects
//-----------------------------------------------------------------------------
class IBase3D {
protected:
    glm::vec3 m_vecPosition;
    glm::mat4 m_matPosition;
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

    glm::mat4 m_matModel;

    void UpdateMatrices() {

        m_Program.BindProgram();
        glUniformMatrix4fv(
            m_Program.GetUniformLoc("mat_Model"), 1, GL_FALSE, glm::value_ptr(m_matModel)
        );

        m_Program.UnbindProgram();
    }
public:
    virtual void Create() = 0;
    virtual void Draw(void) = 0;
    virtual void Update() {};
    virtual ~IInstance3D() = default;

    Buffer* GetVertexBuffer() const noexcept {
        return (Buffer*)&m_VertexBuffer;
    }
    Buffer* GetElementBuffer() const noexcept {
        return (Buffer*)&m_ElementBuffer;
    }
    CLayout* GetLayout() const noexcept {
        return (CLayout*)&m_VertexArray;
    }
    CShaderProgram* GetShaderProgram() const noexcept {
        return (CShaderProgram*)&m_Program;
    }
};
