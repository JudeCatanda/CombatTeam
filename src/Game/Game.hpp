#pragma once

#include "Window.hpp"
#include "Model_Loader.hpp"

class CBaseGame {
public:
    void Init();
    void Update();
    void Render();
    void Destroy(); //alt name: cleanup
private:
    CWindow m_window;
    CModel_Loader m_modelLoader;
    void proccess();
};
