cmake_minimum_required(VERSION 3.26)
project(cpp-board)

set(CMAKE_CXX_STANDARD 23)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(cereal CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

add_executable(cpp-board src/main.cpp
        src/application/WindowContext.cpp
        src/application/WindowContext.h
        src/models/types.cpp
        src/models/types.h
        src/utils/vmath.cpp
        src/utils/vmath.h
        src/models/Ball.cpp
        src/models/Ball.h
        src/models/BallProps.h
        src/logic/GaltonSimulator.cpp
        src/logic/GaltonSimulator.h
        src/models/GaltonProps.h
        src/logic/Collider.cpp
        src/logic/Collider.h
        src/models/ColliderProps.h
        src/application/RenderContext.cpp
        src/application/RenderContext.h
        src/application/EventsHandler.cpp
        src/application/EventsHandler.h
        src/application/modals/ImguiContext.cpp
        src/application/modals/ImguiContext.h
        src/application/modals/ImguiModals.cpp
        src/application/modals/ImguiModals.h
)

target_link_libraries(cpp-board PRIVATE sfml-window sfml-graphics sfml-network sfml-system)
target_link_libraries(cpp-board PRIVATE cereal::cereal)
target_link_libraries(cpp-board PRIVATE imgui::imgui ImGui-SFML::ImGui-SFML)
