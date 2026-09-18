#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> flip(int i, vector<int> &pancakes) {
  // flip starting from under the largest
  std::reverse(pancakes.begin(), pancakes.end() + i - 1); // n
  return pancakes;
}

int main() {
  int n = 5;
  std::vector<int> pancakes = {1, 3, 2, 5, 4};

  for (int i = 0; i < n; i++) {
    int m = max_element(pancakes.begin(), pancakes.end() - i) -
            pancakes.begin(); // n, unsorted array
    flip(m, pancakes);        // n
    flip(i, pancakes);        // n, total = 2n
  }

  for (auto i : pancakes) {
    cout << i << endl;
  }

  // n(n-2), O(n^2 - 2n), take worst case so O(n^2)
}
