cmake_minimum_required(VERSION 3.26)
project(cpp-board)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(cereal CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

add_executable(cpp-board src/main.cpp
        src/aplication/Window.cpp
        src/aplication/Window.h
        src/aplication/Console.cpp
        src/aplication/Console.h
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
        src/models/ColliderProps.h)

target_link_libraries(cpp-board PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
target_link_libraries(cpp-board PRIVATE cereal::cereal)
target_link_libraries(main PRIVATE imgui::imgui)
target_link_libraries(main PRIVATE ImGui-SFML::ImGui-SFML)
