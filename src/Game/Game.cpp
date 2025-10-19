#include "Game.hpp"

void CBaseGame::Init() {
    m_window.Create("CombatTeam!", 600, 800);
    m_modelLoader.CreateLoader("./assets/models/cube.obj");
    m_modelLoader.ReadVertices();
    proccess();
};

void CBaseGame::proccess() {
    while(!m_window.ShouldClose()) {
        Render();
        Update();
    }
};

void CBaseGame::Render() {
    glfwSwapBuffers(m_window.GetHandle());
    glfwPollEvents();
}

void CBaseGame::Update() {

};

void CBaseGame::Destroy() {

};
