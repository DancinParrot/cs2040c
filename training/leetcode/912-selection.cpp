#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void sort(vector<int> &nums) {
  // selection sort O(n^2)
  int n = nums.size();

  for (int i = 0; i < n - 1; ++i) {
    int min_i = i; // assume first is sorted

    for (int j = i + 1; j < n; ++j) {
      if (nums[i] > nums[j]) {
        min_i = j;
      }
    }
    // Swap min_i
    swap(nums[i], nums[min_i]);
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
