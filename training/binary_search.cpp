#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void overflow_demo() {
  int a = INT_MAX, b = INT_MAX;

  cout << a + ((b - a) / 2) << '\n'; // same as below but prevent overflow
  // cout << (a + b) / 2 << '\n'; // signed int overflow!
}

int binary_search(vector<int> nums, int target) {
  int left = 0, right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2; // prev int overflow
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      left = mid + 1;
    else if (nums[mid] > target)
      right = mid - 1;
  }

  return -1;
}

int main() {
  vector<int> nums{1, 2, 3, 4, 6, 7, 9};
  int idx = binary_search(nums, 6);
  if (idx != -1) {
    cout << "Found at index " << idx << '\n';
  } else {
    cout << "Not found" << '\n';
  }
  return 0;
}
