#include "Game.hpp"

void CBaseGame::Init() {
    m_window.Create("CombatTeam!", 600, 800);
    m_modelLoader.CreateLoader("./assets/models/cube.obj");
    m_modelLoader.Read();

    m_Vertex.Create("vcube.glsl", GL_VERTEX_SHADER);
    m_Fragment.Create("fcube.glsl", GL_FRAGMENT_SHADER);

    m_Program.CreateProgram(&m_Vertex, &m_Fragment);

    m_vecModelVertices = m_modelLoader.GetModelVerticesInVector();
    m_vecModelIndices = m_modelLoader.GetModelIndicesInVector();

    m_VertexArray.CreateAndBind();

    m_VertexBuffer.Create(m_vecModelVertices->size() * sizeof(glm::vec3), m_vecModelVertices->data(), GL_STATIC_DRAW, GL_ARRAY_BUFFER);
    m_VertexArray.SetVertexAttrib(0, 3, GL_FLOAT, 3 * sizeof(float), (const GLvoid*)0);

    m_ElementBuffer.Create(m_vecModelIndices->size() * sizeof(unsigned int), m_vecModelIndices->data(), GL_STATIC_DRAW, GL_ELEMENT_ARRAY_BUFFER);

    m_VertexArray.Unbind();
    m_VertexBuffer.Unbind();

    m_Program.UnbindProgram();

    std::cout << "Vertex count: " << m_vecModelVertices->size() << std::endl;
    proccess();
};

void CBaseGame::proccess() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glViewport(0, 0, 800, 600);
    while(!m_window.ShouldClose()) {
        Render();
        Update();
    }
};

void CBaseGame::Render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_Program.BindProgram();
    m_VertexArray.Bind();
    m_VertexBuffer.Bind();
    m_ElementBuffer.Bind();


    glDrawElements(GL_TRIANGLES, m_vecModelIndices->size(), GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(m_window.GetHandle());
    glfwPollEvents();
}

void CBaseGame::Update() {

};

void CBaseGame::Destroy() {

};
