#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void sort(vector<int> &nums) {
  // bubble sort with early exit flag (but still O(n^2))
  int n = nums.size();

  for (int i = 0; i < n - 1; i++) {
    bool is_swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        is_swapped = true;
      }
    }
    if (!is_swapped) {
      break;
    }
  }
}

int main() {
  vector<int> nums({5, 2, 3, 1});
  sort(nums);
  for (auto n : nums) {
    cout << n << '\n';
  }
  return 1;
}
