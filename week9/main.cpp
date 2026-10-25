#include "union-find.hpp"
#include <cassert>
#include <string>

using namespace std;

bool solve(const vector<string> &s) {
  // IDs: a = 0, b = 1, ..., z = 25
  vector<int> ids(26);
  for (int i = 0; i < 26; ++i)
    ids[i] = i;

  UnionFind<int> u(ids);

  // First, merge ALL equalities.
  for (const string &v : s) {
    int a = v.front() - 'a';
    int b = v.back() - 'a';

    if (v[1] == '=')
      u.unionSets(a, b);
  }

  // Then check ALL inequalities.
  for (const string &v : s) {
    int a = v.front() - 'a';
    int b = v.back() - 'a';

    if (v[1] == '!' && u.find(a) == u.find(b))
      return false;
  }

  return true;
}

int main() {
  vector<string> s1 = {"a==d", "b==c", "d==e"};
  vector<string> s2 = {"a==b", "b!=c", "c==a"};

  assert(solve(s1) == true);
  assert(solve(s2) == false);

  return 0;
}
