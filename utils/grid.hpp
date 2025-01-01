#pragma once
#include <vector>

enum CellStatus { DEAD, ALIVE };

class Grid {
  int rows;
  int cols;
  int cellSize;
  std::vector<std::vector<CellStatus>> board;
  std::vector<int> dRow;
  std::vector<int> dCol;

public:
  Grid(int rows, int cols, int size);
  void draw();
  void generateRandom();
  void simulate();
  void setCellValue(int mouseX, int mouseY);
  void clear();

private:
  bool is_valid(int row, int col);
};
