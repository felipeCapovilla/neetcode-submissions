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
    bool isValidBST(TreeNode* root) {
        return valid(root,1001,-1001);
        
    }

    bool valid(TreeNode* node, int maxVal, int minVal){
        if(node == nullptr){
            return true;
        }

        if(node->val >= maxVal || node->val <= minVal){
            return false;
        }

        bool esq,dir;
        esq = valid(node->left,node->val,minVal);
        dir = valid(node->right,maxVal,node->val);

        return esq&&dir;
    }
};
