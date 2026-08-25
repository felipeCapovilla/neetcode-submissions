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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> fila;
        vector<vector<int>> output;

        fila.push(root);
        bfs(fila,output);
        return output;
        
    }

    void bfs(queue<TreeNode*>& fila, vector<vector<int>>& out){
        while(!fila.empty()){
            int tam = fila.size();
            vector<int> level = {};

            for(int k=0; k<tam;k++){
                TreeNode* curr = fila.front();
                fila.pop();
                level.push_back(curr->val);

                if(curr->left != nullptr){
                    fila.push(curr->left);
                }
                if(curr->right != nullptr){
                    fila.push(curr->right);
                } 
            }

            out.push_back(level); 

        }
    }
};
