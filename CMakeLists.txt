cmake_minimum_required(VERSION 3.20)

project(spaceInvaders LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory("lib/SFML")

add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/res"
        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res"
)

add_executable(spaceInvaders main.cpp "game_system.cpp")

target_link_libraries(spaceInvaders PRIVATE sfml-graphics)

set_target_properties(spaceInvaders PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

add_dependencies(spaceInvaders copy_resources)