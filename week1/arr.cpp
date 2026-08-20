#include <iostream>
using namespace std;

int main() {
  int *arr = new int[5];
  arr[2] = 3;

  cout << arr[2] << endl;

  delete[] arr;

  cout << arr[2] << endl;
}
