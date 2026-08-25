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


    return dfs(root,subRoot);
    
        }
        
    


    bool dfs(TreeNode* node, TreeNode* sub){
        
        if(node == nullptr){
            return false;
        }
        
        if(isSame(node,sub)){
            return true;
        }

        return dfs(node->left,sub) || dfs(node->right,sub);
    }

    bool isSame(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }else if((p == nullptr && q != nullptr) || (p!=nullptr && q == nullptr)){
            return false;
        }else if(p->val != q->val){
            return false;
        }else{
            return isSame(p->left,q->left) && isSame(p->right,q->right);
        }
    }
};
