cmake_minimum_required(VERSION 3.20)

project(spaceInvaders LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory("lib/SFML")

add_executable(spaceInvaders main.cpp)

target_link_libraries(spaceInvaders PRIVATE sfml-graphics)