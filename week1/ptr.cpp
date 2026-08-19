#include <bits/stdc++.h>
using namespace std;

void array() {
  int *arr = new int[6];
  // Must include []. Otherwise, mem leak
  delete[] arr;
}

int* foo() {
  int x = 123;
  int* xp = &x;
  return xp;
};

// NOTE: Important, see this
void func() {
  int* ptr = foo();
  *ptr = 999;

  // May print 999 (unreliable) or crash with error. Depends on system and compiler
  cout << *ptr << endl;
}

/*
 * Two pokeballs are fixed, addresses are the same, only their contents change.
 *
 * Remember: Summon pokemon (content) with *a. a is a pokeball or the address
 */
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;   // content of a replaced by content of b
  *b = temp; // content of b replaced by temp
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // Both same, * indicate type, i.e. create an int ptr
  int *ptr1;
  int* ptr2;
  // NOTE: What is the type of *ptr1? Not an integer pointer nor an interger, don't know. See foo() for example

  // Create Pokemon (memory region)
  new int;
  // Need pokeball (ptr) to contain the pokemon (mem region)
  ptr1 = new int;
  *ptr1 = 10;
  // Cout value (summon pokemon out of ball)
  cout << *ptr1 << endl;
  // Cout address
  cout << ptr1 << endl;
  // After use finish, need free "pokemon", does not free "pokeball"
  // Delete content, not ptr. Can still use ptr1
  delete ptr1;
  ptr1 = new int;

  // In C, compiler calls malloc() to create a mem space, and free() when not
  // used
  int x; // an int
  int *ptr_x;
  // NOTE: &x is an integer pointer/address
  ptr_x = &x; // find pokemon's pokeball with &

  int a = 0, b = 0;
  swap(&a, &b);

  return 0;
}
