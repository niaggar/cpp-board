#include "EventsHandler.h"

#include <utility>


EventCallback::EventCallback() {
    this->m_event_type = sf::Event::EventType::Count;
    this->m_callback = nullptr;
    this->m_event_name = "";
}

EventCallback::EventCallback(sf::Event::EventType event_type, std::string event_name, std::function<void(const sf::Event &)> callback) {
    this->m_event_type = event_type;
    this->m_callback = std::move(callback);
    this->m_event_name = std::move(event_name);
}

EventsHandler::EventsHandler() = default;

void EventsHandler::processEvents(sf::Event& event) {
    auto event_type = event.type;

    if (m_event_callbacks.find(event_type) != m_event_callbacks.end()) {
        auto callbacks = m_event_callbacks[event_type];
        for (auto& callback : callbacks) {
            callback.m_callback(event);
        }
    }
}

void EventsHandler::registerCallback(EventCallback &event_manager) {
    auto event_type = event_manager.m_event_type;
    if (m_event_callbacks.find(event_type) == m_event_callbacks.end()) {
        m_event_callbacks[event_type] = std::vector<EventCallback>();
    }

    m_event_callbacks[event_type].push_back(event_manager);
}

void EventsHandler::unregisterCallbacks(EventCallback &event_manager) {
    auto event_type = event_manager.m_event_type;
    if (m_event_callbacks.find(event_type) != m_event_callbacks.end()) {
        auto callbacks = m_event_callbacks[event_type];
        auto it = std::remove_if(callbacks.begin(), callbacks.end(), [event_manager](EventCallback& callback) {
            return callback.m_event_name == event_manager.m_event_name;
        });

        if (it != callbacks.end()) {
            callbacks.erase(it);
        }

        m_event_callbacks[event_type] = callbacks;
    }
}
