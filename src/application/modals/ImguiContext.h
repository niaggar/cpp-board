#pragma once


#include <SFML/Graphics.hpp>
#include "../EventsHandler.h"
#include "ImguiModals.h"


class ImguiContext {
public:
    explicit ImguiContext(sf::RenderWindow &window);

    void draw();
    void processEvent(sf::Event &event);
    void shutdown();
    void addModal(ImguiModal* modal);

private:
    sf::RenderWindow& m_window;
    sf::Clock m_delta_clock;
    std::vector<ImguiModal*> m_modals;
};
