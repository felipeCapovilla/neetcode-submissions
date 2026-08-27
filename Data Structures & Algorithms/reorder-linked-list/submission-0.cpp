class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        inverte(head, head);
    }

    void inverte(ListNode* node, ListNode*& root) {
        if (node == nullptr) {
            return;
        }
        inverte(node->next, root);

   
        if (root == nullptr) {
            return;
        }


        if (root == node || root->next == node) {
            node->next = nullptr;
            root = nullptr; 
            return;
        }

  
        ListNode* temp = root->next;
        root->next = node;
        node->next = temp;
        root = temp;
    }
};