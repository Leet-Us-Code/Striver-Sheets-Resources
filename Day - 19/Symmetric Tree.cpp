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

//Sid 
bool helper(TreeNode *root1, TreeNode *root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL || root2 == NULL)
            return false;
        bool x = helper(root1->left, root2->right);
        bool y = helper(root1->right, root2->left);
        if(root1->val == root2->val && x && y)
            return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        //OM GAN GANAPATHAYE NAMO NAMAH 
        //JAI SHRI RAM 
        //JAI BAJRANGBALI 
        //AMME NARAYANA, DEVI NARAYANA, LAKSHMI NARAYANA, BHADRE NARAYANA
        return helper(root->left, root->right);
    }
