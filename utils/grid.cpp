#include "grid.hpp"
#include "constants.hpp"
#include "raylib.h"
#include <cstdlib>
#include <iostream>
#include <vector>

Grid::Grid(int rows, int cols, int size)
    : rows(rows), cols(cols), cellSize(size) {
  board = std::vector(rows, std::vector(cols, CellStatus::DEAD));
}

void Grid::draw() {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      Color cellColor = board[row][col] == CellStatus::ALIVE
                            ? game_constants::ALIVE_CELL_COLOR
                            : game_constants::DEAD_CELL_COLOR;
      DrawRectangle(col * cellSize, row * cellSize, cellSize - 1, cellSize - 1,
                    cellColor);
    }
  }
}

void Grid::simulate() {

  std::vector<std::vector<CellStatus>> new_board(
      rows, std::vector<CellStatus>(cols, CellStatus::DEAD));

  std::vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
  std::vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {

      int live_neighbours = 0;
      CellStatus curr_status = board[row][col];

      for (int k = 0; k < dx.size(); k++) {
        int new_row = row + dx[k];
        int new_col = col + dy[k];
        if (is_valid(new_row, new_col)) {
          live_neighbours +=
              (board[new_row][new_col] == CellStatus::ALIVE ? 1 : 0);
        }
      }
      if (live_neighbours < 2) {
        new_board[row][col] = CellStatus::DEAD;
      } else if ((live_neighbours == 2 || live_neighbours == 3) &&
                 curr_status == CellStatus::ALIVE) {
        new_board[row][col] = CellStatus::ALIVE;
      } else if (live_neighbours > 3) {
        new_board[row][col] = CellStatus::DEAD;
      } else if (live_neighbours == 3) {
        new_board[row][col] = CellStatus::ALIVE;
      }
    }
  }

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      board[i][j] = new_board[i][j];
    }
  }
}

void Grid::generateRandom() {
  board[1][5] = CellStatus::ALIVE;
  board[2][5] = CellStatus::ALIVE;
  board[1][6] = CellStatus::ALIVE;
  board[2][6] = CellStatus::ALIVE;

  board[11][5] = CellStatus::ALIVE;
  board[11][6] = CellStatus::ALIVE;
  board[11][7] = CellStatus::ALIVE;
  board[12][4] = CellStatus::ALIVE;
  board[12][8] = CellStatus::ALIVE;
  board[13][3] = CellStatus::ALIVE;
  board[13][9] = CellStatus::ALIVE;
  board[14][3] = CellStatus::ALIVE;
  board[14][9] = CellStatus::ALIVE;
  board[15][6] = CellStatus::ALIVE;
  board[16][4] = CellStatus::ALIVE;
  board[16][8] = CellStatus::ALIVE;
  board[17][5] = CellStatus::ALIVE;
  board[17][6] = CellStatus::ALIVE;
  board[17][7] = CellStatus::ALIVE;
  board[18][6] = CellStatus::ALIVE;

  board[21][3] = CellStatus::ALIVE;
  board[21][4] = CellStatus::ALIVE;
  board[21][5] = CellStatus::ALIVE;
  board[22][3] = CellStatus::ALIVE;
  board[22][4] = CellStatus::ALIVE;
  board[22][5] = CellStatus::ALIVE;
  board[23][2] = CellStatus::ALIVE;
  board[23][6] = CellStatus::ALIVE;
  board[25][1] = CellStatus::ALIVE;
  board[25][2] = CellStatus::ALIVE;
  board[25][6] = CellStatus::ALIVE;
  board[25][7] = CellStatus::ALIVE;

  // Add R-pentomino (chaotic growth pattern)
  board[8][10] = CellStatus::ALIVE;
  board[9][11] = CellStatus::ALIVE;
  board[10][9] = CellStatus::ALIVE;
  board[10][10] = CellStatus::ALIVE;
  board[10][11] = CellStatus::ALIVE;

  // Add a Diehard pattern (lasts 130 generations)
  board[24][12] = CellStatus::ALIVE;
  board[25][6] = CellStatus::ALIVE;
  board[25][7] = CellStatus::ALIVE;
  board[25][11] = CellStatus::ALIVE;
  board[25][12] = CellStatus::ALIVE;
  board[25][13] = CellStatus::ALIVE;
  board[23][7] = CellStatus::ALIVE;

  // Add Acorn pattern (grows for over 5200 generations)
  board[4][2] = CellStatus::ALIVE;
  board[6][3] = CellStatus::ALIVE;
  board[3][4] = CellStatus::ALIVE;
  board[4][4] = CellStatus::ALIVE;
  board[6][4] = CellStatus::ALIVE;
  board[4][6] = CellStatus::ALIVE;
  board[4][7] = CellStatus::ALIVE;
}

bool Grid::is_valid(int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols)
    return false;
  return true;
}
