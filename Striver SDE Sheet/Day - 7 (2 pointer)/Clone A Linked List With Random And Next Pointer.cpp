class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node *copy, *start = head;
        while(start != NULL)
        {
            Node *temp = start->next;
            start->next = new Node(start->val);
            start->next->next = temp;
            start = temp;
        }
        start = head;
        while(start != NULL)
        {
            if(start->next != NULL)
                start->next->random = start->random? start->random->next: start->random;
            start = start->next? start->next->next: start->next;
        }
        Node *original = head;
        copy = head->next;
        Node *temp = copy;
        while(original != NULL && copy != NULL)
        {
            original->next = original->next? original->next->next: original->next;
            copy->next = copy->next? copy->next->next: copy->next;
            original = original->next;
            copy = copy->next;
        }
        return temp;
        
    }
};
