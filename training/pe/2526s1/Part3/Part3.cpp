// #include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;
namespace {

// TEST(Part3, simpleFind) {
//   vector<Cell> cells = {{0, 0, 0}, {1, 1, 0}, {2, 0, 1}};
//   UnionFind u(cells);
//   EXPECT_EQ(u.find(0), 0);
//   EXPECT_EQ(u.find(1), 1);
// }
//
// TEST(Part3, simepleUnion) {
//   vector<Cell> cells = {{0, 0, 0}, {1, 1, 0}, {2, 0, 1}};
//   UnionFind u(cells);
//   ASSERT_EQ(u.find(0), 0);
//   ASSERT_EQ(u.find(1), 1);
//   u.unionSet({1, 1, 0}, {0, 0, 0});
//   EXPECT_EQ(u.find(0), 0);
//   EXPECT_EQ(u.find(1), 0);
// }
} // namespace

int countComponents(vector<vector<int>> grid);

// Function to print the 2D grid
void printGrid(const vector<vector<int>> &grid) {
  int rows = grid.size();
  int cols = grid[0].size();

  cout << "Map grid:" << endl;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

// Example usage
int main(int argc, char **argv) {
  // ::testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();
  vector<vector<int>> map = {
      {1, 1, 0, 0, 0}, {1, 0, 0, 1, 1}, {0, 0, 1, 0, 0}, {0, 1, 1, 0, 0}};

  printGrid(map);
  cout << "Number of components: " << countComponents(map) << endl << endl;
  cout << "(The correct answer should be 3)" << endl << endl;

  map[2][3] = 1;
  printGrid(map);
  cout << "Number of components: " << countComponents(map) << endl;
  cout << "(The correct answer should be 2)" << endl;
  return 0;
}
