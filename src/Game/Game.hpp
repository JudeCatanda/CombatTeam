#pragma once

#include "Window.hpp"
#include "Model_Loader.hpp"

#include "Layout.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"

class CBaseGame {
public:
    void Init();
    void Update();
    void Render();
    void Destroy(); //alt name: cleanup
private:
    CWindow m_window;
    CModel_Loader m_modelLoader;

    Buffer m_VertexBuffer, m_ElementBuffer;
    CLayout m_VertexArray;
    CShader m_Fragment, m_Vertex;
    CShaderProgram m_Program;
    std::vector<glm::vec3>* m_vecModelVertices;
    std::vector<unsigned int>* m_vecModelIndices;

    void proccess();
};
