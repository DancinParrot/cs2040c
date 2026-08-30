#include "circularIntLinkedList.h"
#include <iostream>
using namespace std;

ListNode::ListNode(int n) {
  _item = n;
  _next = NULL;
}

////////////////////////////////////////////////////////////////////////////
//      You should ONLY modify the bodies of the following functions      //
// You should copy and paste ALL the functions below onto coursemology    //
////////////////////////////////////////////////////////////////////////////

void CircularList::advanceHead() {
  if (_size == 0) {
    return;
  }
  _head = _head->_next;
}

// NO null pointers except when empty
void CircularList::insertHead(int n) {
  ListNode *node = new ListNode(n);
  if (_head == nullptr) {
    node->_next = node; // point to itself when only 1 element
    _head = node;
  } else {
    // Insert in between head node and its next node, tail should point back to
    // head
    node->_next = _head->_next;
    _head->_next = node;
    // NOTE: How to get tail with O(1)? Swap values of head and new node
    node->_item = _head->_item;
    _head->_item = n;
  }
  _size++;
};

void CircularList::removeHead() {
  if (_size == 0) {
    return;
  }

  ListNode *tmp = _head->_next;

  // Swap head with its next node and delete its next node
  // So, don't change head
  _head->_item = tmp->_item;
  // _head->_next->_item = tmp->_item; // no need this, cause will be removed
  _head->_next = tmp->_next;
  delete tmp;
  _size--;
}

// NO null pointers
void CircularList::print() {
  std::string out = "";

  ListNode *node = _head;

  // tail will never be null as it points to first element
  for (int i = 0; i < _size; i++) {
    out += std::to_string(node->_item);
    if (i < _size - 1) {
      out += " ";
    }
    node = node->_next;
  }

  if (_size > 0) {
    out += " ";
  }

  std::cout << out << std::endl;
}

bool CircularList::exist(int n) {
  ListNode *node = _head;

  // _tail will point to _head so will never be null except empty
  for (int i = 0; i < _size; i++) {
    if (node->_item == n) {
      return true;
    }
    node = node->_next;
  }

  return false;
}

int CircularList::headItem() {
  if (_head == nullptr) {
    throw std::out_of_range("Error: Attempt to access empty list");
  }

  return _head->_item;
}

CircularList::~CircularList() {
  for (int i = 0; i < _size; i++) {
    removeHead();
  }
};
