// Hari

// Check if BTree is height balanced or not

class Solution {
public:
    int htBalChk = 1;
    int helper(TreeNode* curr){
        if(!curr) return 0;
        int left = helper(curr->left);
        int right = helper(curr->right);
        if(abs(left - right) > 1) htBalChk = 0;
        return max(left, right) + 1; // next level 
    }
    
    bool isBalanced(TreeNode* root) {
        htBalChk = 1; // assume its ht balanced initially
        helper(root);
        return htBalChk;
    }
};
