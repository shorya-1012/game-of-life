#pragma once
#include <vector>

enum CellStatus { DEAD, ALIVE };

class Grid {
  int rows;
  int cols;
  int cellSize;
  std::vector<std::vector<CellStatus>> board;

public:
  Grid(int rows, int cols, int size);
  void draw();
  void generateRandom();
  void simulate();

private:
  bool is_valid(int row, int col);
};
