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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v1,v2;

        dfs(p,v1);
        dfs(q,v2);

        return v1 == v2;
        
    }

    void dfs(TreeNode* node, vector<int>&v){
        if(node == nullptr){
            v.push_back(-999);
            return;
        }
        v.push_back(node->val);
        dfs(node->left,v);
        dfs(node->right,v);
    }
};
