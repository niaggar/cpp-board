#pragma once

#include <SFML/Graphics.hpp>
#include <functional>


struct EventCallback {
    EventCallback();
    EventCallback(sf::Event::EventType event_type, std::string event_name, std::function<void(const sf::Event& event)> callback);

    sf::Event::EventType m_event_type;
    std::string m_event_name;
    std::function<void(const sf::Event& event)> m_callback;
};

class EventsHandler {
public:
    EventsHandler();

    void processEvents(sf::Event& event);
    void registerCallback(EventCallback& event_manager);
    void unregisterCallbacks(EventCallback& event_manager);

private:
    std::map<sf::Event::EventType, std::vector<EventCallback>> m_event_callbacks;
};
