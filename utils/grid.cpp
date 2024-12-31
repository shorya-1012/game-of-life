#include "grid.hpp"
#include "constants.hpp"
#include "raylib.h"
/*#include <iostream>*/
#include <cstdlib>
#include <vector>

Grid::Grid(int rows, int cols, int size)
    : rows(rows), cols(cols), cellSize(size) {
  board = std::vector(rows, std::vector(cols, CellStatus::DEAD));
}

void Grid::draw() {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      Color cellColor = board[row][col] == CellStatus::ALIVE
                            ? game_constants::BACKGROUND_COLOR
                            : BLACK;
      DrawRectangle(col * cellSize, row * cellSize, cellSize - 1, cellSize - 1,
                    cellColor);
    }
  }
}

void Grid::generateRandom() {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      int x = rand() % 9;
      if (x == 4) {
        board[row][col] = CellStatus::ALIVE;
      }
    }
  }
}
