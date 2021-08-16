// Hari's
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return 1;
        }
        return 0;
    }
};

//Sid's solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            //check after changing both of them as initially both are the same
            if(slow == fast)
                return true;
        }
        return false;
    }

};
