#include "SuperLongInt.h"
#include <vector>

//////////////////////////////////////////////////////////////////
//  For this first section, you do NOT need to implement this
//  But you are allowed to modify these. However make sure they work
// //////////////////////////////////////////////////////////////////

// unsigned long long int max approximately 1.8 x 10^19
// max integer is 2,147,483,647 with 10 digits

// Inserts an element to the head
void List::push_head(int element) {
  Node *n = new Node(element);
  n->next = m_head;
  m_head = n;
  m_size++;
  if (!m_tail)
    m_tail = m_head;
}

// Removes the head element
int List::pop_head() {
  Node *temp = m_head->next;
  int x = m_head->element;
  delete m_head;
  m_head = temp;
  m_size--;
  return x;
}

//////////////////////////////////////////////////////////////////
//  Second Section: Your REAL tasks start here
//
// //////////////////////////////////////////////////////////////////

// Inserts an element to the tail
void List::push_tail(int element) {
  if (!m_head) {
    push_head(element);
    return;
  }
  Node *n = new Node(element);
  m_tail->next = n;
  m_tail = n;
  m_size++;
}

// Returns a std::string equivalent of the container
std::string SuperLongInt::to_string() const {
  std::string s = "";
  Node *cur = _l.m_head;
  while (cur != nullptr) {
    std::string chunk = std::to_string(cur->element);
    if ((cur != _l.m_tail) && (chunk.length() < 4)) {
      chunk.insert(0, 4 - chunk.length(), '0');
    }
    s.insert(0, chunk);
    cur = cur->next;
  }
  return s;
}

SuperLongInt::SuperLongInt(unsigned long long int i) {
  unsigned long long int x = i;

  // 4-digit chunks: 123450009 = [1234, 5000, 9]
  // 123450009 = [9, 2345, 1]
  while (x > 0) {
    std::vector<int> tmp;
    _l.push_tail(x % 10000);
    x /= 10000;
  }
};

SuperLongInt::SuperLongInt(SuperLongInt a, SuperLongInt b) {
  Node *a_cur = a._l.m_head;
  Node *b_cur = b._l.m_head;

  while (a_cur && b_cur) {
    // NOTE: What if 9000 will be stored as [9]?
    // if got result in 1 more digit, then add to next
    int rounding = 0;
    if (_l.m_head && (_l.m_head->element == -1)) {
      _l.pop_head();
      rounding = 1;
    }
    int sum = a_cur->element + b_cur->element + rounding;
    _l.push_tail(sum % 10000);
    if (sum / 10000 != 0) {
      _l.push_head(-1);
    }
    a_cur = a_cur->next;
    b_cur = b_cur->next;
  }
};
