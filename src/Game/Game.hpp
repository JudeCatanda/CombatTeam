#pragma once

#include "Window.hpp"
#include "Model_Loader.hpp"

#include "Layout.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"

#include <memory>

#include "Instance.hpp"

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
