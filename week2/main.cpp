#include "List.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
  List ll;
  ll.insertAtHead(11);
} // destructor called here

int main() {

  List *lptr;

  lptr = new List();

  // both same
  (*lptr).insertAtHead(11);
  lptr->insertAtHead(12);

  delete lptr;

  return 0;
}
