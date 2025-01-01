#pragma once
#include "raylib.h"

namespace game_constants {
const int MAX_FPS = 60;
const int SCREEN_WIDHT = 1280;
const int SCREEN_HEIGHT = 720;
const Color BACKGROUND_COLOR = DARKGRAY;
const Color ALIVE_CELL_COLOR = Color{31, 203, 14, 255};
const Color DEAD_CELL_COLOR = Color{16, 16, 16, 255};
const int CELL_SIZE = 20;
const int ROWS = SCREEN_HEIGHT / CELL_SIZE;
const int COLS = SCREEN_WIDHT / CELL_SIZE;
} // namespace game_constants
