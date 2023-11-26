#include "RenderContext.h"

RenderContext::RenderContext(sf::RenderWindow &window) : m_window(window) {
    m_view = sf::View(sf::FloatRect(0, 0, 800, 600));
    m_window.setView(m_view);
}

void RenderContext::draw() {
    m_window.clear(sf::Color::Blue);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    m_window.draw(shape);
}

void RenderContext::clear(sf::Color color) {
    m_window.clear(color);
}

void RenderContext::windowResized(sf::FloatRect window_size) {
    m_view.setSize(window_size.width, window_size.height);
    m_window.setView(m_view);
}

void RenderContext::viewDrag(sf::Vector2f delta) {
    auto center = m_view.getCenter();
    m_view.setCenter(center.x + delta.x, center.y + delta.y);
    m_window.setView(m_view);
}

void RenderContext::viewZoom(float zoom) {
    m_view.zoom(zoom);
    m_window.setView(m_view);
}

void RenderContext::viewZoomAt(sf::Vector2f zoom_at, float zoom) {
    m_view.zoom(zoom);
    m_view.setCenter(zoom_at);
    m_window.setView(m_view);
}

void RenderContext::viewSetCenter(sf::Vector2f center) {
    m_view.setCenter(center);
    m_window.setView(m_view);
}
