// Hari

class Solution {
public:
    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(root == nullptr) return true; //leaf reached
        else if(maxNode && root->val >= maxNode->val || minNode && root->val <= minNode->val) {
            return false;
        }
    return helper(root->left, minNode, root) && helper(root->right, root, maxNode);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};


//Sid 

class Solution {
public:
    bool helper(TreeNode *root, long long int min, long long int max)
    {
        if(root == NULL)
            return true;
        if(root->val < max && root->val > min)
        {
            if(helper(root->left, min, root->val) && helper(root->right, root->val, max))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
