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
    int getSize(ListNode *head)
    {
        ListNode *ptr = head;
        int size = 0;
        while(ptr != NULL)
        {
            size++;
            ptr = ptr->next;
        }
        return size;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        if(k > getSize(head))
            return head;
        ListNode *ptr = head;
        ListNode *prev = NULL;
        ListNode *cur = head;
        int c = 0;
        while(cur != NULL && c < k)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            c++;
        }
        ptr->next = reverseKGroup(cur, k);
        return prev;
    }
};

//Iterative soln
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *tmp, *pre = preheader;
        while(cur = cur->next) 
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++) {
                tmp= nex->next;
                nex->next = pre->next;
                pre->next = nex;
                cur->next = tmp;
                nex = tmp;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
    }
};
