//
// Created by nikolay on 10.02.2021.
//

#ifndef YAN_SNAKE_CONSTANTS_H
#define YAN_SNAKE_CONSTANTS_H

#include "SDL.h"

namespace Constants {
    namespace Colors {
        const SDL_Color SNAKE_BODY_ACTIVE = {255, 255, 255, 255};
        const SDL_Color SNAKE_BODY = {150, 150, 150, 255};
        const SDL_Color SNAKE_HEAD = {255, 0, 0, 255};

        const SDL_Color FRUIT = {0, 255, 0, 0};

        const SDL_Color BACKGROUND = {0, 0, 0, 255};
        const SDL_Color BACKGROUND_ENDGAME = {200, 200, 0, 255};
    }

    namespace App {
        const int UPDATE_DELAY = 1000 / 12;

        const int DEFAULT_GRID_WIDTH = 25;
        const int DEFAULT_GRID_HEIGHT = 25;
        const int DEFAULT_TILE_SIZE = 20;
    }
}
#endif //YAN_SNAKE_CONSTANTS_H
