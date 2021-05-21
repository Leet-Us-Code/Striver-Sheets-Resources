// Hari

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right) return root; // if both l and r exist for a node, that node is the LCA. If one of them is null, just pass the non null val up so that the LCA can be found in the future above.
        if(left) return left;
        else return right;        
    }
};
