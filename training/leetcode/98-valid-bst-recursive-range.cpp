#include <climits>
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
class Solution {
private:
  bool validate(TreeNode *node, long minVal, long maxVal) {
    if (!node)
      return true;

    if ((node->val <= minVal) || (node->val >= maxVal)) {
      return false;
    }

    // Left subtree must be < node->val
    bool l = validate(node->left, minVal, node->val);

    // Right subtree must be > node->val
    bool r = validate(node->right, node->val, maxVal);
    return l && r;
  }

public:
  // Approach 2: Range DFS, O(n) time and O(h) space
  bool isValidBST(TreeNode *root) {
    // Valid BST: left subtree < root->val, and right subtree > root-val.
    // (CANNOT BE EQUAL), e.g. [2,2,2]
    return validate(root, LONG_MIN, LONG_MAX);
  }
};
