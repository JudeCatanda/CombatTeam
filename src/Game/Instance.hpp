#pragma once

#include "Layout.hpp"
#include "Shader.hpp"
#include "Buffer.hpp"
#include "Model_Loader.hpp"
#include "glm/glm.hpp"

class IInstance3D {
protected:
    CLayout m_VertexArray;
    Buffer m_VertexBuffer, m_ElementBuffer;

    CShader m_Fragment, m_Vertex;
    CShaderProgram m_Program;

    glm::vec4 m_vecPosition;
    glm::mat4 m_matPosition;
public:
    virtual void Create() = 0;
    virtual void Draw(void) = 0;
    virtual void Update() {
        std::cout << "No Update() was overwriten.\n";
    };
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
