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

/*mit Sentinelwert, das sorgt dafür das wir statt O(n²) zu O(n) werden.
extrem kompliziert bisher. Ich hab 180 Minuten daran gesessen um zu verstehen warum die Balance 
von root mit rechts und links nicht ausreicht und warum wir den Sentinelwert haben und wie wir den returnen.
Das alleine Bedarf einer Präsentation heute Abend.
*/

class Solution{
public:
    bool isBalanced(TreeNode* root){
        if(!root){
            return true;    
        }
        return get_height(root) != -1;
    }

private:
    int get_height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = get_height(root->left);
        if(left == -1){
            return -1;
        }
        int right = get_height(root->right);
        if(right == -1){
            return -1;
        }
        if(std::abs(left-right) > 1){
            return -1;
        }
        return 1 + std::max(left, right);
    }
};
