/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return good(root, root->val);
    }

private:
    int good(TreeNode* node, int maxSoFar) {
        if (!node) {
            return 0;
        }

        int current = 0;

        if (node->val >= maxSoFar) {
            current = 1;
        }

        maxSoFar = std::max(maxSoFar, node->val);

        int left = good(node->left, maxSoFar);
        int right = good(node->right, maxSoFar);

        return current + left + right;
    }
};