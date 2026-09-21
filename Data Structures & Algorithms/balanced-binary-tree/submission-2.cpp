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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        int esq = getH(root->left);
        int dir = getH(root->right);
        
        return (abs(esq-dir) <= 1) && isBalanced(root->left) && isBalanced(root->right); 
    }

    int getH(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        return 1+max(getH(node->left),getH(node->right));
    }
};
