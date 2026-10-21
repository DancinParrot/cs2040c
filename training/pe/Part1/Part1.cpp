
#include "LinkedList.h"
#include "SuperLongInt.h"
#include <iostream>

void push_tail_test1();
void push_tail_test2();

int main() {
  push_tail_test1();
  push_tail_test2();

  SuperLongInt x1(1111222233334444);
  std::cout << 1111222233334444
            << " create the linked list in SuperLongInt as ";
  x1.showList();
  std::cout << "With to_string() output: " << x1.to_string() << std::endl;

  SuperLongInt x2(91111222233334444);
  std::cout << 91111222233334444
            << " create the linked list in SuperLongInt as ";
  x2.showList();
  std::cout << "With to_string() output: " << x2.to_string() << std::endl;

  SuperLongInt x3(123450009);
  std::cout << 123450009 << " create the linked list in SuperLongInt as ";
  x3.showList();
  std::cout << "With to_string() output: " << x3.to_string() << std::endl;

  std::cout << std::endl << std::endl;

  unsigned long long int vec[] = {101,
                                  102,
                                  10001,
                                  4,
                                  5,
                                  10001,
                                  98765,
                                  12345,
                                  9999,
                                  1,
                                  1,
                                  9999,
                                  1999999999,
                                  1,
                                  19999999999999999,
                                  1,
                                  1234567890123456789,
                                  9876543210987654321};
  int vecSize = 18;

  for (int i = 0; i < vecSize / 2; i++) {
    unsigned long long int x = vec[i * 2];
    unsigned long long int y = vec[i * 2 + 1];
    SuperLongInt a(x);
    SuperLongInt b(y);
    std::cout << "a = " << "a.to_string() :" << a.to_string() << "          ";
    std::cout << "b = " << "b.to_string() :" << b.to_string() << std::endl;
    SuperLongInt c(a, b);
    std::cout << "c = a + b and c.to_string():" << c.to_string()
              << "   with c.showList():";
    c.showList();
    std::cout << std::endl;
  }

  unsigned long long int x = 9999999999999999999;
  std::cout << "By normal inaccurate calculation: ";
  std::cout << x << "+" << x << "=" << x + x << std::endl;
  SuperLongInt a(9999999999999999999);
  SuperLongInt b(a, a);
  std::cout << "By SuperLongInt: " << a.to_string() << "+" << a.to_string()
            << "=" << b.to_string() << std::endl
            << std::endl
            << std::endl;

  // you should write more test cases for yourself
}

void push_tail_test1() {
  std::cout << "push_tail_test1()" << std::endl;
  int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  int vecSize = 16;

  List list;
  for (size_t idx = 0; idx < vecSize; idx++) {
    list.push_tail(vec[idx]);
  }

  std::cout << list.to_string() << std::endl;
  /* Should print out:
   * [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
   */
  std::cout << std::endl;
}

void push_tail_test2() {
  std::cout << "push_tail_test2()" << std::endl;
  int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  int vecSize = 16;

  List list;
  for (size_t idx = 0; idx < vecSize; idx++) {
    list.push_tail(vec[idx]);
    if (idx % 3 == 0)
      list.pop_head();
  }

  std::cout << list.to_string() << std::endl;
  /* Should print out:
   * [7,8,9,10,11,12,13,14,15,16]
   */
  std::cout << std::endl;
}
