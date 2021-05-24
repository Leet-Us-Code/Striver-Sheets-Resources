// Hari

class Solution {
public:
    // trace it, you will get it
    void assignLowerLvl(Node* start){
        Node* curr = start;
        while(curr){
            curr->left->next = curr->right;
            if(curr->next){
                curr->right->next = curr->next->left;
            }
            curr = curr->next;
        }
    }
    Node* connect(Node* root) {
        // initially all next are NULL. 
        Node* leftNode = root;
        while(leftNode && leftNode->left){
            assignLowerLvl(leftNode);
            leftNode = leftNode->left;
        }
        return root;
    }
};
