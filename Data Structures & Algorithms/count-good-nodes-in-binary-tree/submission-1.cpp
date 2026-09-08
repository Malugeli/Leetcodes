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
    int count{};
        
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        count = 1;
        good(root->left, root->val);
        good(root->right, root->val);
        return count;
    }

private:
    void good(TreeNode* root, int max){
        if(!root){
            return;
        }
        if(root->val >= max){
            max = root->val;
            ++count;
        }
        good(root->left, max);
        good(root->right, max);
    }
};
