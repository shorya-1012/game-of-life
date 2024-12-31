#pragma once
#include "raylib.h"

namespace game_constants {
const int MAX_FPS = 60;
const int SCREEN_WIDHT = 720;
const int SCREEN_HEIGHT = 900;
const Color BACKGROUND_COLOR = GREEN;
const int CELL_SIZE = 30;
const int ROWS = SCREEN_HEIGHT / CELL_SIZE;
const int COLS = SCREEN_WIDHT / CELL_SIZE;
} // namespace game_constants
