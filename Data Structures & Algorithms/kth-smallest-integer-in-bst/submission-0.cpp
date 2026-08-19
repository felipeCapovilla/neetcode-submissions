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
    int kthSmallest(TreeNode* root, int k) { // Usar um heap de minimo com tamanho definido depois de passar pela arvore inteira.

        vector<int> output;
        queue<TreeNode*> fila;
        priority_queue<int> heap;


        fila.push(root);

        while(!fila.empty()){
            TreeNode* node = fila.front();
            fila.pop();
            heap.push(node->val);

            while(heap.size() > k){
                heap.pop();
            }

            if(node->right != nullptr){
                fila.push(node->right);
            }

            if(node->left != nullptr){
                fila.push(node->left);
            }
        }

        

        return heap.top();

    }
};
