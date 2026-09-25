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
public:
  TreeNode *invertTree(TreeNode *root) {
    // Wishful thinking again, imagine you're at the last case (top of the call
    // stack) when the function is one step away from finishing. E.g. root is 4,
    // left is 2 and right is 7.
    if (!root)
      return nullptr;

    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    // It's postorder (see where u do ur operation)! Once u get left, right.
    // Just swap.
    root->left = right;
    root->right = left;
    return root;
  }
};
