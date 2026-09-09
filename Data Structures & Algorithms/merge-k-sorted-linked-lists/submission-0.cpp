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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;
        int n = lists.size();

        for(int k=0; k<n;k++){
            ListNode* curr = lists[k];

            while(curr!= nullptr){
                nums.push_back(curr->val);
                curr=curr->next;
            }
        }

        sort(nums.begin(),nums.end());

        ListNode* out = new ListNode();
        ListNode* head = out;

        for(int k=0; k<nums.size();k++){
            ListNode* curr = new ListNode(nums[k]);
            out->next = curr;
            out = curr;
        }

        return head->next;


    }
};
