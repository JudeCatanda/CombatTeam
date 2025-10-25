#include "Game.hpp"

void CBaseGame::Init() {
    m_window.Create("CombatTeam!", 600, 800);

    m_Objects.push_back( std::make_unique<CCube>() ) ;

    for(auto& objects : m_Objects) {
        objects->Create();
    }

    m_camera.Create();

    proccess();
};

void CBaseGame::proccess() {
    glDepthFunc(GL_LESS);
    glViewport(0, 0, 800, 600);
    m_camera.SetAspectRatio(m_window.GetAspectRatio());
    m_camera.Send(m_Objects[OBJECT::PLAYER]->GetShaderProgram());

    while(!m_window.ShouldClose()) {
        Render();
        Update();
    }
};

void CBaseGame::Render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    m_window.SetViewport();

    m_camera.SetAspectRatio(m_window.GetAspectRatio());
    m_camera.Send(m_Objects[OBJECT::PLAYER]->GetShaderProgram());
    
    for(auto& objects : m_Objects) {
        objects->Update();
        objects->Draw();
    }

    glfwSwapBuffers(m_window.GetHandle());
    glfwPollEvents();
}

void CBaseGame::Update() {
};

void CBaseGame::Destroy() {

};
