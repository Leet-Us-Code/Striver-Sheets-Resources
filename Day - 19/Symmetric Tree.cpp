// Hari

class Solution {
public:
    bool helper(TreeNode* r1, TreeNode* r2){
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        
        if(r1 && r2 && r1->val == r2->val){
            // check their subtrees
            return helper(r1->left, r2->right) && helper(r1->right, r2->left);
        } 
        return false;
    }
    
    
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};
