//
// Created by nikolay on 08.02.2021.
//

#ifndef YAN_SNAKE_SNAKE_H
#define YAN_SNAKE_SNAKE_H


#include "../application/Renderer.h"
#include "TileRenderer.h"
#include "Grid.h"
#include "../application/ActionManager.h"

class Snake {
    struct Node {
        int x;
        int y;

        Node *next;
        Node *prev;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

    Grid *grid;

public:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

private:
    Direction direction;

    void processInput(const ActionManager &actionManager);
    bool move();

public:
    bool active = false;

    Snake(Grid *grid, int initLen, int posX, int posY, Direction initDirection = RIGHT);
    ~Snake();

    void draw(const TileRenderer &renderer) const;

    bool update(const ActionManager &actionManager);

    void grow();
};


#endif //YAN_SNAKE_SNAKE_H
