#include "ListNode.h"

#ifndef LIST_H
#define LIST_H

class List {
private:
  int size;
  ListNode *head;

public:
  List();
  ~List();
  void insertAtHead(int);
  void removeHead();
};

#endif // !LIST_H
