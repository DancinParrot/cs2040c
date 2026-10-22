//
//  Submission.cpp
//  Part 3
//
//

#include <vector>
using std::vector;

struct Cell {
  size_t idx; // idx in parent array
  int row;
  int col;

  size_t operator[](const Cell &other) const { return other.idx; }
};

class UnionFind {
private:
  vector<Cell> parent;

public:
  UnionFind(vector<Cell> cells) : parent() {
    for (int i = 0; i < cells.size(); ++i) {
      cells[i].idx = i; // update idx
      parent.push_back(cells[i]);
    }
  }
  size_t find(size_t i) {
    size_t root = i;
    while (parent[root].idx != root) {
      root = parent[root].idx;
    }
    return root;
  }
  void unionSet(Cell a, Cell b) {
    size_t a_idx = a.idx;
    size_t b_idx = b.idx;
    while (parent[a_idx].idx != a_idx)
      a_idx = parent[a_idx].idx;
    while (parent[b_idx].idx != b_idx)
      b_idx = parent[b_idx].idx;
    parent[a_idx] = parent[b_idx];
  };
};

// Main function to count number of components (islands)
int countComponents(vector<vector<int>> grid) {
  vector<Cell> cells;
  size_t idx = 0;
  int islands = 0;
  for (int row = 0; row < grid.size(); ++row) {
    for (int col = 0; col < grid[row].size(); ++col) {
      cells.push_back({idx, row, col});
      idx++;
      if (grid[row][col] == 1)
        ++islands;
    }
  }
  UnionFind u(cells);

  int cols = grid[0].size();
  for (int row = 0; row < grid.size(); ++row) {
    for (int col = 0; col < cols; ++col) {
      if (grid[row][col] == 0)
        continue;

      int current = row * cols + col;

      // Check left
      if ((col > 0) && (grid[row][col - 1] == 1)) {
        int left = row * cols + (col - 1);

        if (u.find(current) != u.find(left)) {
          u.unionSet(cells[current], cells[left]);
          --islands;
        }
      }
      // Check up
      if ((row > 0) && (grid[row - 1][col] == 1)) {
        int up = (row - 1) * cols + col;
        if (u.find(current) != u.find(up)) {
          u.unionSet(cells[current], cells[up]);
          --islands;
        }
      }
    }
  }

  return islands;
}
