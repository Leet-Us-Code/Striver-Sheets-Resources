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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *dummy = l3;
        while(l1 != NULL && l2 !=  NULL)
        {
            if(l1->val > l2->val)
            {
                l3->next = l2;
                l2 = l2->next;
            }
            else
            {
                l3->next = l1;
                l1 = l1->next;
            }
            l3 = l3->next;
        }
        if(l1)
            l3->next = l1;
        if(l2)
            l3->next = l2;
        return dummy->next;
    }
};


// Hari's

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *res = ans;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                res->next = l1;
                l1 = l1->next;
            }
            else if(l1->val >= l2->val){
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        
        if(l1 != nullptr){
            res->next = l1;
        }
        
        if(l2 != nullptr){
            res->next = l2;
        }
               
        return ans->next;
    }
};
