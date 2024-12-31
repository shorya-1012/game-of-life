#include "raylib.h"
#include "utils/constants.hpp"
#include "utils/grid.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  InitWindow(game_constants::SCREEN_WIDHT, game_constants::SCREEN_HEIGHT,
             "Game of Life");
  SetTargetFPS(game_constants::MAX_FPS);

  // setup grid
  Grid grid(game_constants::ROWS, game_constants::COLS,
            game_constants::CELL_SIZE);

  grid.generateRandom();
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(game_constants::BACKGROUND_COLOR);

    grid.draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
