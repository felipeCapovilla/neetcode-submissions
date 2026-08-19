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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr){
            return true;
        }
        if(root == nullptr && subRoot != nullptr){
            return false;
        }
        if(same_tree(root,subRoot)){
            return true;
        }

        bool esq,dir;
        esq = isSubtree(root->left,subRoot);
        dir = isSubtree(root->right,subRoot);

        if(esq || dir){
            return true;
        }

        return false;
        
    }

    bool same_tree(TreeNode* p, TreeNode* q) {
        vector<int> v1,v2;

        dfs(p,v1);
        dfs(q,v2);

        return (v1 == v2 ? true : false);
    }


    void dfs(TreeNode* node, vector<int>& values){
        if(node == nullptr){
            values.push_back(-1);
            return;
        }

        values.push_back(node->val);
        dfs(node->left,values);
        dfs(node->right,values);
        
    }
    
};
