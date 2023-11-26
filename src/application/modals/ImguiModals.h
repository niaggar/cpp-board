#pragma once


#include <imgui.h>
#include "../RenderContext.h"


class ImguiModal {
public:
    virtual void draw() = 0;
    virtual void shutdown() = 0;
};

class FPSModal : public ImguiModal {
public:
    void draw() override {
        ImGui::SetNextWindowPos(ImVec2(10, 10));
        ImGui::Begin("FPS", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        ImGui::End();
    }

    void shutdown() override {}
};

class OptionsModal : public ImguiModal {
public:
    void draw() override {
        ImGui::Begin("Options");
        ImGui::Text("Options");

        ImGui::Separator();
        ImGui::BeginGroup();

        ImGui::Checkbox("Add balls", &this->m_can_add_balls);
        ImGui::Checkbox("Add walls", &this->m_can_add_obstacles);

        ImGui::EndGroup();
        ImGui::End();

        if (this->m_can_add_balls) {
            m_can_add_obstacles = false;
            this->drawAddBalls();
        }

        if (this->m_can_add_obstacles) {
            m_can_add_balls = false;
            this->drawAddObstacles();
        }
    }

    void shutdown() override {}

private:
    bool m_show = true;
    bool m_can_add_balls = false;
    bool m_can_add_obstacles = false;

    void drawAddBalls() {
        ImGui::Begin("Add balls");
        ImGui::Text("Add balls");
        ImGui::Separator();
        ImGui::BeginGroup();

        static float mass = 1.0f;
        ImGui::SliderFloat("Mass", &mass, 0.1f, 10.0f);

        ImGui::EndGroup();
        ImGui::End();
    }

    void drawAddObstacles() {

    }
};

class CameraModal : public ImguiModal {
public:
    explicit CameraModal(RenderContext& render_context) : m_render_context(render_context) {}

    void draw() override {
        ImGui::Begin("Camera");
        ImGui::Text("Camera");
        ImGui::Separator();
        ImGui::BeginGroup();

        auto view = this->m_render_context.getView();
        auto view_center = view.getCenter();
        auto view_size = view.getSize();

        ImGui::Text("View center: (%.1f, %.1f)", view_center.x, view_center.y);
        ImGui::Text("View size: (%.1f, %.1f)", view_size.x, view_size.y);

        if (ImGui::Button("Reset view")) {
            this->m_render_context.viewZoomAt({0.0f, 0.0f}, 1.0f);
        }

        ImGui::EndGroup();
        ImGui::End();
    }

    void shutdown() override {}

private:
    RenderContext& m_render_context;
};
