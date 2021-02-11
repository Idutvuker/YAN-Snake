//
// Created by nikolay on 08.02.2021.
//

#ifndef YAN_SNAKE_WINDOW_H
#define YAN_SNAKE_WINDOW_H

#include <string>
#include <SDL.h>

class Window {
    SDL_Window *handle;
public:
    Window(const std::string &title, int width, int height);
    ~Window();

    void setResizable(SDL_bool resizable);

    SDL_Window * getHandle() const;
};


#endif //YAN_SNAKE_WINDOW_H
