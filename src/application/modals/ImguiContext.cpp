#include <imgui-SFML.h>
#include <imgui.h>
#include "ImguiContext.h"
#include "ImguiModals.h"

ImguiContext::ImguiContext(sf::RenderWindow &window) : m_window(window) {
    auto status = ImGui::SFML::Init(m_window);
    if (!status) {
        throw std::runtime_error("Failed to initialize ImGui");
    }
}

void ImguiContext::draw() {
    ImGui::SFML::Update(m_window, m_delta_clock.restart());

    for (auto modal : this->m_modals) {
        modal->draw();
    }

    ImGui::SFML::Render(m_window);
}

void ImguiContext::processEvent(sf::Event &event) {
    ImGui::SFML::ProcessEvent(event);
}

void ImguiContext::shutdown() {
    for (auto modal : this->m_modals) {
        modal->shutdown();
    }

    ImGui::SFML::Shutdown();
}

void ImguiContext::addModal(ImguiModal *modal) {
    this->m_modals.push_back(modal);
}


