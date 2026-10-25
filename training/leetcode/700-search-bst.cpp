#include <cstdlib>

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
  int dfs(TreeNode *node, double target, int closest) {
    if (node == nullptr)
      return closest;

    // If is closest, change closest value
    double curDiff = abs(node->val - target);
    double closestDiff = abs(closest - target);

    if ((curDiff < closestDiff) ||
        (curDiff == closestDiff && node->val < closest))
      closest = node->val;

    if (target < node->val) {
      return dfs(node->left, target, closest);
    } else {
      return dfs(node->right, target, closest);
    }
  }

public:
  int closestValue(TreeNode *root, double target) {
    return dfs(root, target, root->val);
  }
};
