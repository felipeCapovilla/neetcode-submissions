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
        fila.push(root);

        vector<vector<int>> output;

        while(!fila.empty()){

            int tam = fila.size();
            vector<int> level = {};

            for(int k=0;k<tam;k++){
                TreeNode* node = fila.front();
                fila.pop();

                level.push_back(node->val);
                if(node != nullptr){
                    if(node-> left != nullptr){
                        fila.push(node->left);
                    }
                    if(node->right != nullptr){
                        fila.push(node->right);
                    }
                
            }
                
            }
            output.push_back(level);



        }

        return output;
        
    }
};
