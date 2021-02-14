#include "constants.h"
#include "game/Game.h"

int main(int argc, char *argv[]) {
    int gridW = Constants::App::DEFAULT_GRID_WIDTH;
    int gridH = Constants::App::DEFAULT_GRID_HEIGHT;
    int tileSize = Constants::App::DEFAULT_TILE_SIZE;

    Game game(gridW, gridH, tileSize);

    game.run();

    return 0;
}