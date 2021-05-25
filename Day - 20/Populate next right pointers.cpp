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

//Sid 
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL || root->right == NULL)
            return root;
        //connection part 
        root->left->next = root->right;
        if(root->next != NULL)
        {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};
