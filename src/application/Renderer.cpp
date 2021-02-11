//
// Created by nikolay on 08.02.2021.
//

#include "SDL.h"
#include "Renderer.h"

Renderer::Renderer(const Window &window) {
    handle = SDL_CreateRenderer(window.getHandle(), -1, SDL_RENDERER_ACCELERATED);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(handle);
}

void Renderer::setDrawColor(const SDL_Color &color) const {
    SDL_SetRenderDrawColor(handle, color.r, color.g, color.b, color.a);
}

void Renderer::clear() const {
    SDL_RenderClear(handle);
}

void Renderer::drawRect(const SDL_Rect &rect) const {
    SDL_RenderFillRect(handle, &rect);
}

void Renderer::present() const {
    SDL_RenderPresent(handle);
}
