// Hari

class BSTIterator {
public:
    // while a list can be used to iterate tree, store value and check
    // space will be O(N). We will do partial inorder w stack for O(h)
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    void helper(TreeNode* curr){
        // move left as per inorder, keep adding to stack in the process
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
    }
    
    int next() { // explores right subT (if exists) of stack top node (inorder fashion)
        TreeNode* temp = s.top(); s.pop();
        helper(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
