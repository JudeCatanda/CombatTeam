#pragma once

#include "Window.hpp"
#include "Model_Loader.hpp"

#include "Layout.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"

#include <memory>

#include "Instance.hpp"


//-----------------------------------------------------------------------------
// Purpose: no magic numbers for accessing m_Objects
//-----------------------------------------------------------------------------
enum OBJECT {
    PLAYER = 0,
    MAP_SECTION_1,
    NONE
};

class CBaseGame {
private:
    CWindow m_window;
    CCamera m_camera;

    std::vector< std::unique_ptr<IInstance3D> > m_Objects;

    void proccess();
public:
    void Init();
    void Update();
    void Render();
    void Destroy(); //alt name: cleanup
};
