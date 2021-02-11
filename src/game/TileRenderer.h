//
// Created by nikolay on 09.02.2021.
//

#ifndef YAN_SNAKE_TILERENDERER_H
#define YAN_SNAKE_TILERENDERER_H


#include "../application/Renderer.h"

class TileRenderer {
    Renderer *renderer;
    int tileSize;

public:
    explicit TileRenderer(Renderer *renderer, int tileSize);

    void drawTile(int x, int y, const SDL_Color &color) const;
};


#endif //YAN_SNAKE_TILERENDERER_H
