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

  bool run = false;
  // setup grid
  Grid grid(game_constants::ROWS, game_constants::COLS,
            game_constants::CELL_SIZE);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(game_constants::BACKGROUND_COLOR);

    if (IsKeyPressed(KEY_R)) {
      grid.generateRandom();
    }

    if (IsKeyDown(KEY_S)) {
      std::cout << "stopping\n";
      run = false;
    }

    if (IsKeyDown(KEY_C)) {
      grid.clear();
    }

    if (IsKeyPressed(KEY_ENTER)) {
      run = true;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      try {
        grid.setCellValue(GetMouseX(), GetMouseY());
      } catch (int) {
        std::cout << "Inside the toolbox\n";
      }
    }

    grid.draw();

    DrawText(
        "Random Grid : R", 10,
        (game_constants::SCREEN_HEIGHT - game_constants::TOOL_BAR_HEIGHT + 5),
        30, WHITE);

    DrawText(
        "Solve : Enter", 270,
        (game_constants::SCREEN_HEIGHT - game_constants::TOOL_BAR_HEIGHT + 5),
        30, WHITE);

    DrawText(
        "Stop : S", 500,
        (game_constants::SCREEN_HEIGHT - game_constants::TOOL_BAR_HEIGHT + 5),
        30, WHITE);

    DrawText(
        "Clear : C", 650,
        (game_constants::SCREEN_HEIGHT - game_constants::TOOL_BAR_HEIGHT + 5),
        30, RED);

    if (run) {
      grid.simulate();
      std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
