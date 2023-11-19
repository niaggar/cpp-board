#pragma once

#include <SFML/Graphics.hpp>



class RenderContext {
public:
    RenderContext(sf::RenderWindow& window);

    void draw();
    void clear(sf::Color color = sf::Color::Black);
    void windowResized(sf::FloatRect window_size);
    void viewDrag(sf::Vector2f delta);
    void viewZoom(float zoom);
    void viewZoomAt(sf::Vector2f zoom_at, float zoom);
    void viewSetCenter(sf::Vector2f center);

private:
    sf::RenderWindow& m_window;
    sf::View m_view;
};
