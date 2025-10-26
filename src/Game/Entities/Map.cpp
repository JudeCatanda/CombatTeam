#include "Map.hpp"

void CCube::Create() {
    m_Loader.CreateLoader("./assets/models/cube.obj");
    m_Loader.Read();

    m_Vertex.Create(GetShaderFromMapDir("vcube.glsl"), GL_VERTEX_SHADER);
    m_Fragment.Create(GetShaderFromMapDir("fcube.glsl"), GL_FRAGMENT_SHADER);

    m_Program.CreateProgram(&m_Vertex, &m_Fragment);

    m_vecModelVertices = m_Loader.GetModelVerticesInVector();
    m_vecModelIndices = m_Loader.GetModelIndicesInVector();

    m_VertexArray.CreateAndBind();

    m_VertexBuffer.Create(m_vecModelVertices->size() * sizeof(glm::vec3), m_vecModelVertices->data(), GL_STATIC_DRAW, GL_ARRAY_BUFFER);
    m_VertexArray.SetVertexAttrib(0, 3, GL_FLOAT, 3 * sizeof(float), (const GLvoid*)0);
    m_ElementBuffer.Create(m_vecModelIndices->size() * sizeof(unsigned int), m_vecModelIndices->data(), GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER);

    m_VertexArray.Unbind();
    m_VertexBuffer.Unbind();

    m_Program.UnbindProgram();
    
    m_matModel = glm::mat4(1.0f);
};

void CCube::Update() {
    float angle = (float)glfwGetTime() * 1.0f;
    m_matModel = glm::mat4(1.0f);
    m_matModel = glm::translate(m_matModel, glm::vec3(0.0f, -1.0f, 0.0f));
    m_matModel = glm::rotate(m_matModel, angle, glm::vec3(0.0f, 1.0f, 0.0f));
    m_matModel = glm::scale(m_matModel, glm::vec3(0.3f));

    UpdateMatrices();
};

void CCube::Draw(void) {
    m_Program.BindProgram();
    m_VertexArray.Bind();
    m_VertexBuffer.Bind();
    m_ElementBuffer.Bind();

    glDrawElements(GL_TRIANGLES, m_vecModelIndices->size(), GL_UNSIGNED_INT, 0);
};
