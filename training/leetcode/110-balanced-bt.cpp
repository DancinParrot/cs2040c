#include <algorithm>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/*
 * O(n) bottom-up DFS via preorder traversal. O(h) stack size.
 */
class Solution {
private:
  int check(TreeNode *node) {
    // Use -1 as flag for unbalanced. Leaf node (no children) will return 0;
    // if one node is unbalanced, the rest will be unbalanced, just return all
    // the way
    if (!node)
      return 0;
    int l = check(node->left);
    if (l == -1)
      return -1; // no need check right, already unbalanced
    int r = check(node->right);
    if (r == -1)
      return -1; // same reason as above
    // post order
    if (abs(l - r) > 1)
      return -1;
    return 1 + max(l, r);
  }

public:
  bool isBalanced(TreeNode *root) { return check(root) != -1; }
};
