// Hari

class Solution {
public:
    void helper(TreeNode* A){
        // merge left subtree into right, make left subT as null and add the previous right subT after new rightsubT 
        // base case
        if(A == nullptr || A->left == nullptr && A->right == nullptr) return;
        if(A->left){
            helper(A->left); // we will go till 3, and as next left is null, we will go up to 2 and then go to 4.
            TreeNode* temp = A->right;
            A->right = A->left;
            A->left = nullptr;
            
            TreeNode* curr = A->right;
            while(curr->right) curr = curr->right;
            //merge the old right 
            curr->right = temp;
        }
        helper(A->right);
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};

//Sid 
void flatten(TreeNode* root) {
        //OM GAN GANAPATHAYE NAMO NAMAH 
        //JAI SHRI RAM 
        //JAI BAJRANGBALI 
        //AMME NARAYANA, DEVI NARAYANA, LAKSHMI NARAYANA, BHADRE NARAYANA
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        if(root->left != NULL)
        {
            flatten(root->left);
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *cur = root->right;
            while(cur->right != NULL)
            {
                cur = cur->right;
            }
            cur->right = temp;
            
        }
        flatten(root->right);
    }
