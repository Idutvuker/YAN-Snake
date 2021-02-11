//
// Created by nikolay on 08.02.2021.
//

#include "Game.h"

void Game::draw(const Renderer &renderer) {
    grid.drawFruit(tileRenderer);

    for (auto snake: snakes)
        snake->draw(tileRenderer);
}

void Game::update(const ActionManager &actionManager) {
    if (gameState == ENDGAME)
        return;

    if (actionManager.isJustPressed(SDL_SCANCODE_SPACE)) {
        snakes[activeSnakeIndex]->active = false;
        activeSnakeIndex = (activeSnakeIndex + 1) % (int) snakes.size();
        snakes[activeSnakeIndex]->active = true;
    }

    for (auto snake: snakes)
        if (!snake->update(actionManager))
            gameState = ENDGAME;
}

Game::Game(int gridW, int gridH, int tileSize) :
        Application("Snake", gridW * tileSize, gridH * tileSize),
        grid(gridW, gridH),
        tileRenderer(&renderer, tileSize) {
    snakes.push_back(new Snake(&grid, 4, gridW / 2, gridH / 2));
    snakes.push_back(new Snake(&grid, 4, 0, 0));

    activeSnakeIndex = 0;
    snakes[activeSnakeIndex]->active = true;

    grid.respawnFruit();
}

Game::~Game() {
    for (auto snake: snakes) {
        delete snake;
    }
}

