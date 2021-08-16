// Hari

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        while(curr){
            if(curr->val == val) return curr; //base
            else if(curr->val < val){
                curr = curr->right;
            }
            else curr = curr->left;
        }
        return nullptr;
    }
};

//Sid 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return root;
        if(root->val == val)
            return root;
        else if(root->val > val)
        {
            return searchBST(root->left, val);
        }
        else 
        {
            return searchBST(root->right, val);
        }
    }
};
