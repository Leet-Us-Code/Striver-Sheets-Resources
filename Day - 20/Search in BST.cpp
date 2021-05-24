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
