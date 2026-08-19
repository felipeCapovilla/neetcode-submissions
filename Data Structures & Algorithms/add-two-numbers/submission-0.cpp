class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        // Continua enquanto houver nós em l1, l2 OU se sobrou um carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int d1 = (l1 != nullptr) ? l1->val : 0;
            int d2 = (l2 != nullptr) ? l2->val : 0;

            int sum = d1 + d2 + carry;
            carry = sum / 10; // Atualiza o carry (ex: 12 / 10 = 1)
            int d = sum % 10;   // Pega apenas a unidade (ex: 12 % 10 = 2)

            curr->next = new ListNode(d);
            curr = curr->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        ListNode* result = dummy->next;
        delete dummy; // Libera a memória do nó dummy
        return result;
    }
};