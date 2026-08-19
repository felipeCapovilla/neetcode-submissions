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
        ListNode* fast;
        ListNode* slow; 
        
        fast = head;
        slow = head;

        for(int k=0; k<n;k++){
            fast=fast->next;
        }

        if(fast == nullptr){
            ListNode* tmp;
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }

        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return head;

        
    }
};
