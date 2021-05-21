// Hari

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // check if nodes are none or not, then if value matches or not. If value matches, check if they are in the same subtree / position in their resp. tree
        
        // base cases
        if(!p && !q) return true; // both nullptr then valid
        else if(!p || !q) return false; // only one of them is null
        else if(p->val != q->val) return false; // nodes exist but diff values
        else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // nodes are the same. Now compare their subtrees and if any one of them don't match then invalid
    }
};
