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


// erster BFS!

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if(!root)
        {
            return result;
        }

        std::queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()){
            int level_size = static_cast<int>( nodes.size() );
            std::vector<int> level;
            level.reserve(level_size);

            for(int i = 0; i < level_size; ++i){
                auto node = nodes.front();
                nodes.pop();
                level.push_back(node->val);

                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);
                }
            }
            result.push_back(std::move(level));
        }
        return result; 
    }
};