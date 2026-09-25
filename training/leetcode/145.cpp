// 145. Binary Tree Postorder Traversal
#include <vector>
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
  vector<int> res;

public:
  void traverse(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    // pre-order position
    traverse(root->left);
    // in-order position
    traverse(root->right);
    // post-order position
    res.push_back(root->val);
  }

  vector<int> preorderTraversal(TreeNode *root) {
    traverse(root);
    return res;
  }
};
