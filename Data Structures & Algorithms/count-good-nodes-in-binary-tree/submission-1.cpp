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
        int cont=0;
        int maior=INT_MIN;
        dfs(root,maior,&cont);
        return cont;
        
    }
    

    void dfs(TreeNode* node, int maior, int* cont){
        if(node == nullptr){
            return;
        }

        if(node->val >= maior){
            (*cont)++;
        }

        maior = max(node->val,maior);
        dfs(node->left,maior,cont);
        dfs(node->right,maior,cont);
    }

};
