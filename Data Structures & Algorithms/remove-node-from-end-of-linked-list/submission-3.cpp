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
        
        int tam = getSize(head);
        
        if(tam == 1){
            return nullptr;
        }

        int node_idx = tam-n;
        remove(head,node_idx);
        return head;


    }

    int getSize(ListNode* head){
        if(head == nullptr){
            return 0;
        }
        return 1+getSize(head->next);
    }

    void remove(ListNode*& head, int node_idx){
        if(node_idx == 0){
            head = head->next;
            return;
        }

        int curr_idx =0;
        ListNode* curr_node = head;

        while(curr_idx != node_idx -1){
            curr_node = curr_node->next;
            curr_idx++;
        }

        curr_node->next = curr_node->next->next;
    }

};
