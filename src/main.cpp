#include <imgui-SFML.h>
#include "application/WindowContext.h"


int main() {
    WindowContext window_context("Galton Board", sf::Vector2u(800, 600));
    window_context.setFramerateLimit(60);

    while (window_context.isRunning()) {
        window_context.run();
        window_context.display();
    }

    return 0;
}
