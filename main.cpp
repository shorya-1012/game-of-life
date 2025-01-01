#include "raylib.h"
#include "utils/constants.hpp"
#include "utils/grid.hpp"
#include <chrono>
#include <iostream>
#include <thread>

int main() {
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

    grid.simulate();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
