//
// Created by nikolay on 08.02.2021.
//

#include <cassert>
#include "Snake.h"
#include "TileRenderer.h"
#include "../constants.h"

Snake::Snake(Grid *grid, unsigned int initLen, int posX, int posY, Direction initDirection) :
        grid(grid),
        direction(initDirection)
{
    assert(initLen > 1 && "Initial snake length should be greater than one");

    head = new Node{posX, posY, nullptr, nullptr};
    Node *lastNode = head;

    grid->takeTile(lastNode->x, lastNode->y);

    for (int i = 1; i < initLen; i++) {
        Node *node = new Node{posX - i, posY};
        lastNode->next = node;
        node->prev = lastNode;

        lastNode = node;
        grid->takeTile(lastNode->x, lastNode->y);
    }

    tail = lastNode;
}

void Snake::draw(const TileRenderer &renderer) const {
    SDL_Color headColor = Constants::Colors::SNAKE_HEAD;
    SDL_Color bodyColor = Constants::Colors::SNAKE_BODY;

    if (active)
        bodyColor = Constants::Colors::SNAKE_BODY_ACTIVE;

    Node *node = head;
    while (node != nullptr) {
        renderer.drawTile(node->x, node->y, node == head ? headColor : bodyColor);

        node = node->next;
    }
}

bool Snake::update(const ActionManager &actionManager) {
    if (active)
        processInput(actionManager);

    return move();
}

void Snake::processInput(const ActionManager &actionManager) {
    if (actionManager.isPressed(SDL_SCANCODE_RIGHT) && direction != LEFT)
        direction = RIGHT;

    else if (actionManager.isPressed(SDL_SCANCODE_LEFT) && direction != RIGHT)
        direction = LEFT;

    else if (actionManager.isPressed(SDL_SCANCODE_UP) && direction != DOWN)
        direction = UP;

    else if (actionManager.isPressed(SDL_SCANCODE_DOWN) && direction != UP)
        direction = DOWN;
}

bool Snake::move() {
    int headX = head->x;
    int headY = head->y;

    switch (direction) {
        case UP:
            headY -= 1;
            break;
        case DOWN:
            headY += 1;
            break;
        case LEFT:
            headX -= 1;
            break;
        case RIGHT:
            headX += 1;
            break;
    }

    headX = (grid->width + headX) % grid->width;
    headY = (grid->height + headY) % grid->height;

    grid->freeTile(tail->x, tail->y);

    head->prev = tail;
    tail->next = head;

    head = tail;
    tail = tail->prev;

    tail->next = nullptr;
    head->prev = nullptr;

    head->x = headX;
    head->y = headY;

    Grid::Tile::State oldTileState = grid->getTileState(head->x, head->y);

    grid->takeTile(head->x, head->y);

    if (oldTileState == Grid::Tile::FRUIT) {
        grow();
        grid->respawnFruit();
    }

    else if (oldTileState == Grid::Tile::SNAKE) {
        return false;
    }

    return true;
}

void Snake::grow() {
    tail->next = new Node{tail->x, tail->y, nullptr, tail};
    tail = tail->next;
}

Snake::~Snake() {
    Node *node = head;
    while (node) {
        Node *next = node->next;
        delete node;
        node = next;
    }
}
