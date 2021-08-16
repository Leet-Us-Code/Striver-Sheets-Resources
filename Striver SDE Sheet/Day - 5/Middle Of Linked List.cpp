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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *ptr = head;
        while(cur != NULL)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }   
};

// Hari's

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
