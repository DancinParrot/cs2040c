#include <bits/stdc++.h>
using namespace std;

class BankAcct {
private:
  int _acc_num;
  double _balance;

public:
  int withdraw(double amt);
  void deposit(double amt) {}
};

// Can also write function body outside of class
int BankAcct::withdraw(double amt) {
  cout << "Hello" << '\n';
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  BankAcct alan, billy;
  alan.deposit(100);
  alan.withdraw(50);

  billy.deposit(20);
  billy.withdraw(10);

  return 0;
}
