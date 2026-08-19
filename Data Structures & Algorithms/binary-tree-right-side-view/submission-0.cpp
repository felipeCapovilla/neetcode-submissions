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
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == nullptr){
            return {};
        }

        queue<TreeNode*> fila;
        vector<int> output;

        fila.push(root);

        while(!fila.empty()){
            
            int n = fila.size();
            vector<int> level = {};

            for(int k=0; k<n;k++){

                TreeNode* curr_node = fila.front();
                fila.pop();

                level.push_back(curr_node->val);

                if(curr_node != nullptr){
                    if(curr_node->left != nullptr){
                        fila.push(curr_node->left);
                    }
                    if(curr_node->right != nullptr){
                        fila.push(curr_node->right);
                    }
                }    
            }

            output.push_back(level[n-1]);
        }

        return output;
    }
};
