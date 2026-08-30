#include <iostream>
void square_val(int *);

int main() {
  int a = 42;
  int *x = &a;
  square_val(x);
  a += 5;
  std ::cout << "Value: " << a << std ::endl;
}

void square_val(int *z) { (*z) = (*z) * (*z); }
