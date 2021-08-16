// Hari's

class Solution {
public:
    int counter(ListNode *head){
        ListNode *curr = head;
        int count = 0;
        
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }
        return count;
    }
    
    ListNode *findInter(ListNode *headA, ListNode *headB, int diff){
        // moved headA by diff so starting point is same
        ListNode *currA = headA;
        ListNode *currB = headB;
        
        for(int i = 0; i<diff; i++){
            if(currA == nullptr) return nullptr;
            currA = currA->next;
        }
        
        while(currA != nullptr && currB != nullptr){
            if(currA == currB) return currA;
            
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = counter(headA);
        int lenB = counter(headB);
        
        int d = abs(lenA - lenB);
        if(lenA > lenB){
            return findInter(headA, headB, d);
        }
        else return findInter(headB, headA, d);
    }
};

//Siddharth's solution 

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = getSize(headA);
        int b = getSize(headB);
        ListNode *ptra = headA;
        ListNode *ptrb = headB;
        if(a > b)
        {
            int c = a-b;
            while(ptra != NULL && c--)
            {
                ptra = ptra->next;
            }
        }
        else
        {
            int c = b - a;
            while(ptrb != NULL && c--)
            {
                ptrb = ptrb->next;
            }
        }
        while(ptra != NULL && ptrb != NULL)
        {
            if(ptra == ptrb)
                return ptra;
            ptra = ptra->next;
            ptrb = ptrb->next;
        }
        return NULL;
    }
};
