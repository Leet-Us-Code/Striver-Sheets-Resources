// Hari

class Solution {
public:
    int index = 1, kthSmall = 0;
    void inOrder(TreeNode* root, int k){
        if(!root) return;
        inOrder(root->left, k);
        // reach smallest ele on left most of tree
        if(index++ == k) {
            kthSmall = root->val; return;
        }
        inOrder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return kthSmall;
    }
};
