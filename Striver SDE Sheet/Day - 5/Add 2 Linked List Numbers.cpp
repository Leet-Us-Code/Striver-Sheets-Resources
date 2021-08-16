// Hari's

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newL = new ListNode(0);
        ListNode *res = newL;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;
            res->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            res = res->next;
        }
        
        while(l1 != nullptr){
            int sum = l1->val + carry;
            res->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            res = res->next;
        }
        
        while(l2 != nullptr){
            int sum = l2->val + carry;
            res->next = new ListNode(sum % 10);
            carry = sum / 10;
            l2 = l2->next;
            res = res->next;
        }
        
        if(carry != 0){
            res->next = new ListNode(carry);
        }
        return newL->next;
    }
};
