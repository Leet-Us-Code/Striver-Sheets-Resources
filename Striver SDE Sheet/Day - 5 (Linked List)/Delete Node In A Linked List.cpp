//Sid's solution
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *cur = node;
        ListNode *prev;
        while(cur->next != NULL)
        {
            prev = cur;
            cur->val = cur->next->val;
            cur = cur->next;
        }
        prev->next = NULL;
    }
};
