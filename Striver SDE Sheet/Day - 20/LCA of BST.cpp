// Hari

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // This is for normal BT. BST property not used
//         if(!root) return nullptr;
//         if(root == p || root == q) return root;
        
//         TreeNode* left = lowestCommonAncestor(root->left, p,q);
//         TreeNode* right = lowestCommonAncestor(root->right, p,q);
        
//         if(left && right) return root;
//         if(left) return left;
//         else return right;
        
        // BST usage
        // we keep recursing till p and q split up. That place is the LCA of BST
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};
