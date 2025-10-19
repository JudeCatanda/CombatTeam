#include "Window.hpp"

int main() {
    CWindow window;
    window.Create("CombatTeam", 800, 600);

    while(!window.ShouldClose()) {
        //?
    }

    window.Destroy();
};
