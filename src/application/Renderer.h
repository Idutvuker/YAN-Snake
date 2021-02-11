//
// Created by nikolay on 08.02.2021.
//

#ifndef YAN_SNAKE_RENDERER_H
#define YAN_SNAKE_RENDERER_H

#include "SDL.h"
#include "Window.h"

class Renderer {
    SDL_Renderer *handle;

public:
    explicit Renderer(const Window &window);
    ~Renderer();

    void setDrawColor(const SDL_Color &color) const;
    void drawRect(const SDL_Rect &rect) const;
    void clear() const;
    void present() const;
};


#endif //YAN_SNAKE_RENDERER_H
