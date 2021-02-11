//
// Created by nikolay on 08.02.2021.
//

#include <iostream>
#include "Window.h"

Window::Window(const std::string &title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("SDL Init Error: " + std::string(SDL_GetError()));
    }

    handle = SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,SDL_WINDOW_SHOWN);
    if (handle == nullptr) {
        throw std::runtime_error("SDL Create Window Error: " + std::string(SDL_GetError()));
    }
}

Window::~Window() {
    SDL_DestroyWindow(handle);
    SDL_Quit();
}

void Window::setResizable(SDL_bool resizable) {
    SDL_SetWindowResizable(handle, resizable);
}

SDL_Window * Window::getHandle() const {
    return handle;
}
