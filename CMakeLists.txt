cmake_minimum_required(VERSION 3.17)
project(YAN_Snake)

set(CMAKE_CXX_STANDARD 14)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wno-long-long -pedantic")
endif()

add_compile_definitions(SDL_MAIN_HANDLED)

set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)

add_subdirectory("external/SDL2")
include_directories("external/SDL2/include")

add_executable(YAN_Snake
        src/main.cpp src/application/Window.cpp src/application/Renderer.cpp src/game/Snake.cpp
        src/game/Game.cpp src/application/Application.cpp src/application/Application.h
        src/application/ActionManager.cpp src/game/TileRenderer.cpp src/game/Grid.cpp
        src/constants.h)

target_link_libraries(YAN_Snake SDL2main SDL2-static)