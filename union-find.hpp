#include <vector>

#ifndef UNION_FIND_H
#define UNION_FIND_H

template <typename T> class UnionFind {
private:
  std::vector<T> _parent;

public:
  UnionFind();
  UnionFind(std::initializer_list<T> init_list);
  T find(T element);
  void unionSets(T a, T b);
};

template <typename T> UnionFind<T>::UnionFind() : _parent{} {}

template <typename T>
UnionFind<T>::UnionFind(std::initializer_list<T> init_list) : _parent{} {
  // Every node's parent is itself at first
  _parent.resize(init_list.size());
  for (size_t i = 0; i < init_list.size(); ++i) {
    _parent[i] = i;
  }
}

/*
 * Path compression guarantees O(log n) for find() and union() by pointing each
 * node to the root
 */
template <typename T> T UnionFind<T>::find(T element) {
  if (element != _parent[element]) {
    _parent[element] = find(_parent[element]);
  }
  return _parent[element];
}

template <typename T> void UnionFind<T>::unionSets(T a, T b) {
  T root_a = find(a);
  T root_b = find(b);

  if (root_a != root_b) {
    _parent[root_b] = root_a;
  }
}

#endif // !UNION_FIND_H
