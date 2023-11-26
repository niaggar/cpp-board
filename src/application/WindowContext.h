#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "RenderContext.h"
#include "EventsHandler.h"
#include "modals/ImguiContext.h"


class WindowContext {
public:
    WindowContext(const std::string& window_name, sf::Vector2u window_size);
    ~WindowContext();

    void processEvents();
    void processModals();
    void run();
    void display();
    void setFramerateLimit(int limit);
    void close();
    bool isRunning() const;

private:
    std::string m_window_name;
    sf::RenderWindow m_window;
    sf::Clock m_delta_clock;
    RenderContext m_render_context;
    ImguiContext m_imgui_context;
    EventsHandler m_events_handler;

    void registerCallbacks();
    void registerModals();
};
