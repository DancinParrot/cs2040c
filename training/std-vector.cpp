#include <iomanip>
#include <iostream>
#include <vector>

/*
 * This example showcases amortized time of O(1) for push_back thanks to
 * doubling optimzation. Consequently, a vector's capacity (number of elements
 * it can hold at a given point in time) will be doubled when needed (size ==
 * capacity), allowing elements to be inserted without reallocation.
 *
 * NOTE: Doubling optimzation will be disabled in debug builds! Disable debug
 * compiler flags i.e. -D_GLIBCXX_DEBUG, -fsanitize=address.
 */
int main() {
  int sz = 100;
  std::vector<int> v;

  auto cap = v.capacity();
  std::cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';

  std::cout << "\nDemonstrate the capacity's growth policy."
               "\nSize:  Capacity:  Ratio:\n"
            << std::left;
  while (sz-- > 0) {
    v.push_back(sz);
    if (cap != v.capacity()) {
      std::cout << std::setw(7) << v.size() << std::setw(11) << v.capacity()
                << std::setw(10) << v.capacity() / static_cast<float>(cap)
                << '\n';
      cap = v.capacity();
    }
  }

  std::cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity()
            << '\n';
}
