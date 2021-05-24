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
