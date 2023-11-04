cmake_minimum_required(VERSION 3.26)
project(cpp-board)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(cereal CONFIG REQUIRED)

add_executable(cpp-board src/main.cpp)

target_link_libraries(cpp-board PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
target_link_libraries(cpp-board PRIVATE cereal::cereal)
