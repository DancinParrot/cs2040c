//
//  Submission.cpp
//  Part 3
//
//

#include <vector>
using std::vector;

class UnionFind {
private:
  vector<int> parent;

public:
  UnionFind(int n) : parent(n) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int i) {}
  void unionSet(int a, int b) {};

  // Main function to count number of components (islands)
  int countComponents(vector<vector<int>> grid) { return 0; }
