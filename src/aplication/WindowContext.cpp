#include "WindowContext.h"
#include "EventsHandler.h"

WindowContext::WindowContext(const std::string& window_name, sf::Vector2u window_size) : m_render_context(this->m_window)
{
    this->m_window.create(sf::VideoMode(window_size.x, window_size.y), window_name);

    this->registerCallbacks();
}

WindowContext::~WindowContext() = default;

void WindowContext::processEvents() {
    sf::Event event{};
    while (this->m_window.pollEvent(event)) {
        this->m_events_handler.processEvents(event);
    }
}

void WindowContext::run() {
    this->processEvents();
    this->m_render_context.draw();
}

void WindowContext::display() {
    this->m_window.display();
}

void WindowContext::setFramerateLimit(int limit) {
    this->m_window.setFramerateLimit(limit);
}

void WindowContext::close() {
    this->m_window.close();
}

bool WindowContext::isRunning() const {
    return this->m_window.isOpen();
}

void WindowContext::registerCallbacks() {
    auto cameraKeyCallback = [&](sf::Event event) {
        if (event.key.code == sf::Keyboard::Left) {
            this->m_render_context.viewDrag({-10.0f, 0.0f});
        }
        if (event.key.code == sf::Keyboard::Right) {
            this->m_render_context.viewDrag({10.0f, 0.0f});
        }
        if (event.key.code == sf::Keyboard::Up) {
            this->m_render_context.viewDrag({0.0f, -10.0f});
        }
        if (event.key.code == sf::Keyboard::Down) {
            this->m_render_context.viewDrag({0.0f, 10.0f});
        }
    };

    auto cameraResizeCallback = [&](sf::Event event) {
        auto size_rect = sf::FloatRect(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
        this->m_render_context.windowResized(size_rect);
    };

    auto cameraZoomCallback = [&](sf::Event event) {
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
            if (event.mouseWheelScroll.delta > 0) {
                this->m_render_context.viewZoom(0.9f);
            } else if (event.mouseWheelScroll.delta < 0) {
                this->m_render_context.viewZoom(1.1f);
            }
        }
    };

    auto closeKeyCallback = [&](sf::Event event) {
        if (event.key.code == sf::Keyboard::Escape) {
            this->close();
        }
    };

    auto closeEventCallback = [&](sf::Event event) {
        this->close();
    };

    auto cameraKeyEventManager = EventCallback(sf::Event::KeyPressed, "cameraKeyCallback", cameraKeyCallback);
    auto cameraResizeEventManager = EventCallback(sf::Event::Resized, "cameraResizeCallback", cameraResizeCallback);
    auto cameraZoomEventManager = EventCallback(sf::Event::MouseWheelScrolled, "cameraZoomCallback", cameraZoomCallback);
    auto closeKeyEventManager = EventCallback(sf::Event::KeyPressed, "closeKeyCallback", closeKeyCallback);
    auto closeEventEventManager = EventCallback(sf::Event::Closed, "closeEventCallback", closeEventCallback);

    this->m_events_handler.registerCallback(cameraKeyEventManager);
    this->m_events_handler.registerCallback(cameraResizeEventManager);
    this->m_events_handler.registerCallback(cameraZoomEventManager);
    this->m_events_handler.registerCallback(closeKeyEventManager);
    this->m_events_handler.registerCallback(closeEventEventManager);
}
