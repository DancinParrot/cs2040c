#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode {
private:
  int item;
  ListNode *next;

private:
  ListNode(int);

  friend class List; // List can access private vars
};

#endif // !LISTNODE_H
