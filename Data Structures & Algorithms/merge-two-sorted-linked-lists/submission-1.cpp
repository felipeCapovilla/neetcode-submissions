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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* lista = new ListNode();
        ListNode* root = lista;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                lista->next=list1;
                list1 = list1->next;
            }else{
                lista->next = list2;
                list2 = list2->next;
            }

            lista = lista->next;
        }

        while(list1 != nullptr){
            lista->next = list1;
            list1 = list1->next;
            lista = lista->next;
        }

        while(list2 != nullptr){
            lista->next = list2;
            list2=list2->next;
            lista = lista->next;
        }

        return root->next;
        
    }
};
