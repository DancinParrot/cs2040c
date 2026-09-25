#include <queue>
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
  vector<vector<int>> res;

public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    queue<TreeNode *> q;
    q.push(root);
    int depth = 1;

    while (!q.empty()) {
      int sz = q.size();
      vector<int> level;
      while (sz-- > 0) {
        TreeNode *cur = q.front();
        q.pop();

        // visit(cur);
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
        level.push_back(cur->val);
      }
      depth++;
      res.push_back(level);
    }
    return res;
  }
};
