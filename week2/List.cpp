#include "List.h"
#include "ListNode.h"

List::List() {}

// Insert at beginning (prepending)
void List::insertAtHead(int n) {
  ListNode *node = new ListNode(n);
  // ListNode's next is a private property, so must declare List as friend in
  // ListNode class
  node->next = head;
  head = node;
  size++;
}

void List::removeHead() {
  if (size > 0) {
    ListNode *tmp = head;
    head = head->next;
    delete tmp;
    size--;
  } else {
    // TODO:
  }
}

List::~List() {
  while (size != 0) {
    removeHead();
  }
}
