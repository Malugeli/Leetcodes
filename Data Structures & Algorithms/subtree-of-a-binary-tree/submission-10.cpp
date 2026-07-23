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

class Solution{
    public:
    bool isSubtree(TreeNode* root, TreeNode* subtree){
        if(!root){
            return false;
        }
        if(isSame(root, subtree)){
            return true; 
        }
        return isSubtree(root->left, subtree) || isSubtree(root->right, subtree);
    }
private:
    bool isSame(TreeNode* root, TreeNode* subtree){
        if(!root && !subtree){
            return true;
        }
        if(!root || !subtree){
            return false;
        }
        return root->val == subtree->val && isSame(root->left, subtree->left) && isSame(root->right, subtree->right);
    }
};