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

//Sid 
bool helper(TreeNode *root, int &h)
    {
        if(root == NULL)
        {
            h = 0; 
            return true;
        }
        int lh = 0, rh = 0;
        bool l = helper(root->left, lh);
        bool r = helper(root->right, rh);
        h = max(lh, rh) + 1;
        if(l && r && abs(lh-rh) <= 1)
            return true;
        else
            return false;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return helper(root, height);
    }
