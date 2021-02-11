//
// Created by nikolay on 08.02.2021.
//

#ifndef YAN_SNAKE_GAME_H
#define YAN_SNAKE_GAME_H


#include "../application/Application.h"
#include "Snake.h"
#include "Grid.h"

class Game : public Application {
    Grid grid;
    std::vector<Snake*> snakes;
    TileRenderer tileRenderer;

    enum State {
        RUNNING,
        ENDGAME
    } gameState = RUNNING;

    int activeSnakeIndex;

protected:
    void draw(const Renderer &renderer) override;

    void update(const ActionManager &actionManager) override;

public:
    Game(int gridW, int gridH, int tileSize);
    ~Game();
};


#endif //YAN_SNAKE_GAME_H
