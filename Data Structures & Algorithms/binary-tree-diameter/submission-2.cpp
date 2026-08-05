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
    int diameterOfBinaryTree(TreeNode* root){
        int diameter{}; 
        get_height(root, diameter);
        return diameter;    
    }
    private:
    int get_height(TreeNode* root, int& diameter){
        if(!root){
            return 0;  
        }
        int height_left = get_height(root->left, diameter);
        int height_right = get_height(root->right, diameter);
        diameter = std::max(diameter, height_left + height_right);
        return std::max(height_left, height_right) + 1;
    }
};