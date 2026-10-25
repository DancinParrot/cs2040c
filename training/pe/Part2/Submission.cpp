#include "BST.h"
#include <iostream>
#include <string>
#include <vector>

//////////////////////////////////////////////////////////////////
//  For this first section, you do NOT need to implement this
//  These are here just for compilation purposes, and please do not modify these
//  However, please include these for your submission
// //////////////////////////////////////////////////////////////////

bool operator>(const Pair &lhs, const Pair &rhs) { return lhs._idx > rhs._idx; }

bool operator<(const Pair &lhs, const Pair &rhs) { return lhs._idx < rhs._idx; }

std::ostream &operator<<(std::ostream &os, const Pair &obj) {
  os << "(" << obj._idx << "," << obj._item << ")";
  return os; // Return ostream& to enable chaining
}

bool operator==(const Pair &lhs, const Pair &rhs) {
  return (lhs._idx == rhs._idx);
}

//////////////////////////////////////////////////////////////////
//  Second Section: Your REAL tasks start here
//
// //////////////////////////////////////////////////////////////////

void SparseArray::store(unsigned long long idx, int x) {
  Pair p = Pair(idx, x);
  TreeNode<Pair> *node = _tree._search(_tree._root, p);
  if (!node) {
    _tree.insert(p);
    return;
  }
  // else already exists, so delete and insert
  // Case 1: No child
  if (!node->_left && !node->_right) {
    // cout << "no child" << '\n';
    node->_item = p;
    return;
  }

  // Case 2: Either left or right exists, then just replace
  if (node->_left) {
    node = node->_left;
    _tree._size--;
    _tree.insert(p);
    return;
  } else {
    node = node->_right;
    _tree._size--;
    _tree.insert(p);
    return;
  }

  // Case 3: Both left and right children exist, use successor
  // go right then left
  TreeNode<Pair> *suc = node;
  suc = node->_right;
  while (suc) {
    suc = suc->_left;
  }
  node = suc;
  delete suc;
  _tree._size--;
  _tree.insert(p);
}

std::string SparseArray::listString(unsigned long long start,
                                    unsigned long long end) {
  std::vector<Pair> arr;
  // inorder traversal then pad in between with 0s?
  auto inorder = [&](auto &self, TreeNode<Pair> *node) {
    if (!node)
      return;
    self(self, node->_left);
    // std::cout << node->_item << '\n';
    arr.push_back(node->_item);
    self(self, node->_right);
  };
  inorder(inorder, _tree._root);
  vector<int> sparse(end - start, 0);

  for (auto p : arr) {
    if (p._idx < start)
      continue;
    if (p._idx > end)
      break;
    int idx = p._idx - start;
    sparse[idx] = p._item;
  }

  string s = "[";
  for (auto c : sparse) {
    s += to_string(c) + ',';
  }
  s.pop_back();
  s += "]";
  return s;
}

//////////////////////////////////////////////////////////////////
//  Third Section: You can modify this to improve efficiency
//
// //////////////////////////////////////////////////////////////////

// template <class T>
// TreeNode<T> *BinarySearchTree<T>::_insert(TreeNode<T> *current, T x) {
//   if (current->_item > x) {
//     if (current->_left)
//       current->_left = _insert(current->_left, x);
//     else {
//       current->_left = new TreeNode<T>(x);
//       _size++;
//     }
//   } else if (x > current->_item) {
//     if (current->_right)
//       current->_right = _insert(current->_right, x);
//     else {
//       current->_right = new TreeNode<T>(x);
//       _size++;
//     }
//   } else
//     return current; // When the node already existed in the tree
//
//   // check bal factor then rotate
//   return current;
// }

template <class T> T max_height(T a, T b) { return (a > b) ? a : b; }

template <class T>
TreeNode<T> *BinarySearchTree<T>::_insert(TreeNode<T> *current, T x) {
  if (!current) {
    TreeNode<T> *node = new TreeNode<T>(x);
    _size++;
    return node;
  }

  if (x < current->_item) {
    current->_left = _insert(current->_left, x);
  } else if (x > current->_item) {
    current->_right = _insert(current->_right, x);
  }

  auto height = [](TreeNode<T> *node) { return (node) ? node->_height : -1; };

  current->_height =
      max_height(height(current->_left), height(current->_right)) + 1;

  // check bal factor
  auto balance = [&](TreeNode<T> *node) {
    return height(node->_left) - height(node->_right);
  };

  // Rebalance
  if (balance(current) > 1) {          // L case
    if (balance(current->_left) < 0) { // LR case
      current->_left = _leftRotation(current->_left);
    }
    current = _rightRotation(current);
  }
  if (balance(current) < -1) {          // R case
    if (balance(current->_right) > 0) { // RL case
      current->_right = _rightRotation(current->_right);
    }
    current = _leftRotation(current);
  }

  return current;
}

// Counterclockwise
template <class T>
TreeNode<T> *BinarySearchTree<T>::_leftRotation(TreeNode<T> *a) {
  TreeNode<T> *b = a->_right;
  TreeNode<T> *b_child = b->_left;
  b->_left = a;
  a->_right = b_child;

  auto height = [](TreeNode<T> *node) { return (node) ? node->_height : -1; };
  a->_height = max_height(height(a->_left), height(a->_right)) + 1;
  b->_height = max_height(height(b->_left), height(b->_right)) + 1;
  return b;
}

// Clockwise
template <class T>
TreeNode<T> *BinarySearchTree<T>::_rightRotation(TreeNode<T> *a) {
  TreeNode<T> *b = a->_left;
  TreeNode<T> *b_child = b->_right;
  b->_right = a;
  a->_left = b_child;

  auto height = [](TreeNode<T> *node) { return (node) ? node->_height : -1; };
  a->_height = max_height(height(a->_left), height(a->_right)) + 1;
  b->_height = max_height(height(b->_left), height(b->_right)) + 1;
  return b;
}
