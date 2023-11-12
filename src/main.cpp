#include <iostream>
#include <cereal/archives/json.hpp>
#include <SFML/Graphics.hpp>


int main() {
    auto videoMode = sf::VideoMode(200, 300);
    auto window = new sf::RenderWindow(videoMode, "CPP Board");

    while (window->isOpen()) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
}
