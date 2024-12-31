#pragma once
#include <vector>

enum CellStatus { ALIVE, DEAD };

class Grid {
  int rows;
  int cols;
  int cellSize;
  std::vector<std::vector<CellStatus>> board;

public:
  Grid(int rows, int cols, int size);
  void draw();
  void generateRandom();
};
