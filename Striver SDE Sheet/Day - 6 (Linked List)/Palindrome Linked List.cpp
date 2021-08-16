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

//Siddharth's solution 
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
    bool helper(ListNode **left, ListNode *right)
    {
        if(*left == NULL || right == NULL)
            return true;
        bool remaining = helper(&(*left), right->next);
        if(remaining)
        {
            if((*left)->val == right->val)
            {
                (*left) = (*left)->next;
                return true;
            }
            return false;
        }
        else
        {
            return false;
        }
    }
    bool isPalindrome(ListNode* head) {
        ListNode *left = head;
        ListNode *right = head;
        return helper(&left, right);
    }
};
