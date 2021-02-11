#include <iostream>
#include "SDL.h"

#include "game/Game.h"

int main(int argc, char *argv[]) {
    Game game(25, 25, 20);

    game.run();

    return 0;
}