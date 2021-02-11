//
// Created by nikolay on 09.02.2021.
//

#ifndef YAN_SNAKE_GRID_H
#define YAN_SNAKE_GRID_H

#include <random>
#include <vector>
#include "TileRenderer.h"

class Grid {
public:
    const int width;
    const int height;

    struct Tile {
        enum State {
            FREE,
            SNAKE,
            FRUIT
        } state = FREE;
    };

private:
    std::vector<Tile> tiles;
    std::pair<int, int> fruitPosition = {-1, -1};

    std::mt19937 randomGenerator;

public:
    Grid(int gridW, int gridH);

    void takeTile(int x, int y);
    void freeTile(int x, int y);

    void respawnFruit();
    void drawFruit(const TileRenderer &tileRenderer);

    Tile::State getTileState(int x, int y);
};


#endif //YAN_SNAKE_GRID_H
