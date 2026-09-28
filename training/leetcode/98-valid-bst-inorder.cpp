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
  TreeNode *prev;

public:
  // Approach 1: Inorder traversal, if cur < prev then INVALID. O(n) time and
  // O(h) space
  bool isValidBST(TreeNode *root) {
    // Valid BST: left subtree < root->val, and right subtree > root-val.
    // (CANNOT BE EQUAL), e.g. [2,2,2]
    if (!root)
      return true;

    bool l = isValidBST(root->left);
    if (prev) {
      if (root->val <= prev->val) {
        return false;
      }
    }
    prev = root;
    bool r = isValidBST(root->right);
    return l && r;
  }
};
