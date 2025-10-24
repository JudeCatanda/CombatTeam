#include "Game.hpp"

void CBaseGame::Init() {
    m_window.Create("CombatTeam!", 600, 800);

    m_Objects.push_back( std::make_unique<CCube>() ) ;

    for(auto& objects : m_Objects) {
        objects->Create();
    }

    m_camera.Create();
    m_camera.SetAspectRatio((float)*(m_window.GetAspectRatio()));

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
    
    for(auto& objects : m_Objects) {
        objects->Draw();
        objects->Update();
    }

    glfwSwapBuffers(m_window.GetHandle());
    glfwPollEvents();
}

void CBaseGame::Update() {

};

void CBaseGame::Destroy() {

};
