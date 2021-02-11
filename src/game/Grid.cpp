//
// Created by nikolay on 09.02.2021.
//

#include <iostream>
#include "Grid.h"
#include "../constants.h"

Grid::Grid(int gridW, int gridH) : width(gridW), height(gridH), tiles(gridW * gridH),
                                   randomGenerator(std::random_device()()) {}

void Grid::takeTile(int x, int y) {
    if (0 <= x && x < width && 0 <= y && y <= height)
        tiles[y * width + x].state = Tile::State::SNAKE;
}

void Grid::freeTile(int x, int y) {
    if (0 <= x && x < width && 0 <= y && y <= height)
        tiles[y * width + x].state = Tile::FREE;
}

void Grid::respawnFruit() {
    std::vector<size_t> freeTileIndices;

    for (size_t i = 0; i < tiles.size(); i++) {
        if (tiles[i].state == Tile::FREE)
            freeTileIndices.push_back(i);
    }

    if (!freeTileIndices.empty()) {
        int randIndex = std::uniform_int_distribution<>(0, freeTileIndices.size() - 1)(randomGenerator);

        size_t tileIndex = freeTileIndices[randIndex];
        tiles[tileIndex].state = Tile::FRUIT;
        fruitPosition = {tileIndex % width, tileIndex / width};
    }
    else {
        // No free space for the fruit
        fruitPosition = {-1, -1};
    }
}

Grid::Tile::State Grid::getTileState(int x, int y) {
    if (0 <= x && x < width && 0 <= y && y <= height)
        return tiles[y * width + x].state;

    return Tile::FREE;
}

void Grid::drawFruit(const TileRenderer &tileRenderer) {
    if (fruitPosition != std::make_pair(-1, -1)) {
        tileRenderer.drawTile(fruitPosition.first, fruitPosition.second, Constants::Colors::FRUIT);
    }
}

