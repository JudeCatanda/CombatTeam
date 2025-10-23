#pragma once

#include "Window.hpp"
#include "Model_Loader.hpp"

#include "Layout.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"

#include <memory>

#include "Instance.hpp"

class CBaseGame {
public:
    void Init();
    void Update();
    void Render();
    void Destroy(); //alt name: cleanup
private:
    CWindow m_window;
    std::vector< std::unique_ptr<IInstance3D> > m_Objects;
    void proccess();
};
