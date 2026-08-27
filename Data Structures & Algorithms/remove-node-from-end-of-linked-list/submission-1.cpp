/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tam  = getSize(head);
        
        if(tam == 1){
            return nullptr;
        }
        if(n == tam){
            return head->next;
        }
        
        int target_idx = tam-n;


        ListNode* l = head;
        ListNode* r = head->next;

        for(int k=2; k<=target_idx;k++){
            l = l->next;
            r = r->next;
        }
        
        l->next = r->next;
        delete(r);

        return head;

    }

    int getSize(ListNode* root){
        if(root == nullptr){
            return 0;
        }

        return 1+getSize(root->next);
    }
};
