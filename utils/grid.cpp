#include "grid.hpp"
#include "constants.hpp"
#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include <vector>

Grid::Grid(int rows, int cols, int size)
    : rows(rows), cols(cols), cellSize(size) {
  board = std::vector(rows, std::vector(cols, CellStatus::DEAD));
  dRow = {1, -1, 0, 0, 1, -1, 1, -1};
  dCol = {0, 0, 1, -1, 1, -1, -1, 1};
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

  std::vector<std::vector<CellStatus>> newBoard(
      rows, std::vector<CellStatus>(cols, CellStatus::DEAD));

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {

      int liveNeighbours = 0;
      CellStatus currStatus = board[row][col];

      for (int k = 0; k < dRow.size(); k++) {
        int newRow = row + dRow[k];
        int newCol = col + dCol[k];
        if (is_valid(newRow, newCol)) {
          liveNeighbours +=
              (board[newRow][newCol] == CellStatus::ALIVE ? 1 : 0);
        }
      }
      if (liveNeighbours < 2) {
        newBoard[row][col] = CellStatus::DEAD;
      } else if ((liveNeighbours == 2 || liveNeighbours == 3) &&
                 currStatus == CellStatus::ALIVE) {
        newBoard[row][col] = CellStatus::ALIVE;
      } else if (liveNeighbours > 3) {
        newBoard[row][col] = CellStatus::DEAD;
      } else if (liveNeighbours == 3) {
        newBoard[row][col] = CellStatus::ALIVE;
      }
    }
  }

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      board[i][j] = newBoard[i][j];
    }
  }
}

void Grid::setCellValue(int mouseX, int mouseY) {
  // calc the pos of the row and col
  if (mouseY > game_constants::GRID_HEIGHT)
    throw 1;
  int row = mouseY / game_constants::CELL_SIZE;
  int col = mouseX / game_constants::CELL_SIZE;
  board[row][col] = CellStatus::ALIVE;
}

void Grid::generateRandom() {
  srand(std::time(nullptr));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int x = rand() % 8;
      if (x == 1) {
        board[i][j] = CellStatus::ALIVE;
      }
    }
  }
}

void Grid::clear() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board[i][j] = CellStatus::DEAD;
    }
  }
}

bool Grid::is_valid(int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols)
    return false;
  return true;
}
