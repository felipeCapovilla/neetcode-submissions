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
        return dfs(root)[0] == 1;
        
    }

    vector<int> dfs(TreeNode* node){
        if(node == nullptr){
            return {1,0};
        }

        vector<int> dir = dfs(node->right);
        vector<int> esq = dfs(node->left);

        bool balanceada = (esq[0] == 1 && dir[0] == 1) && (abs(dir[1] - esq[1]) <= 1);
        int altura = 1 +max(esq[1],dir[1]);

        return {balanceada ? 1 : 0, altura};
    }
};
