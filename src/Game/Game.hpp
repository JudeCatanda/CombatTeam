#pragma once

#include "Window.hpp"

class CBaseGame {
public:
    void Init();
    void Update();
    void Render();
    void Destroy(); //alt name: cleanup
private:
    CWindow m_window;
    void proccess();
};
