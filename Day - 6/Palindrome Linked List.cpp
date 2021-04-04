// Hari's 

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *curr = head;
        stack<int> stk;
        
        while(curr != nullptr){
            stk.push(curr->val);
            curr = curr->next;
        }
        
        while(head != nullptr){
            int Top = stk.top(); stk.pop();
            if(Top != head->val) return false;
            head = head->next;
        }
        return true;
    }
};
