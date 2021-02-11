//
// Created by nikolay on 09.02.2021.
//

#include "TileRenderer.h"

TileRenderer::TileRenderer(Renderer *renderer, int tileSize) : renderer(renderer), tileSize(tileSize) {}

void TileRenderer::drawTile(int x, int y, const SDL_Color &color) const {
    SDL_Rect rect{x * tileSize, y * tileSize, tileSize, tileSize};

    renderer->setDrawColor(color);
    renderer->drawRect(rect);
}

