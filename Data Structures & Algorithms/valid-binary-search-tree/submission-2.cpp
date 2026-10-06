class Solution {
public:
  bool isValidBST(TreeNode *root) {
    struct Node {
      TreeNode *node;
      int low;
      int high;
    };

    std::queue<Node> q;
    q.push({root, INT_MIN, INT_MAX});
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      if (curr.node->val <= curr.low || curr.node->val >= curr.high) {
        return false;
      }
      if (curr.node->left) {
        q.push({curr.node->left, curr.low, curr.node->val});
      }
      if (curr.node->right) {
        q.push({curr.node->right, curr.node->val, curr.high});
      }
    }
    return true;
  }
};
