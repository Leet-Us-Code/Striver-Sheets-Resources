// Hari

int helper(TreeNode* curr, int &d){
        if(curr == nullptr) return 0;
        
        int left = helper(curr->left, d);
        int right = helper(curr->right, d);
        
        d = max(d, left+right); // keeps check of maxDia for each node and at the end it will have maxDia for whole tree
        return max(left, right) + 1; // for next lvl (see finding maxDepth qn)
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        // In finding ht of tree, we just calc max ht for each node by finding max depth of its left and right node + 1 (curr node) and return this val for the next level
        // For dia, its very similar to this. Max dia = max(dia, left+right)
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
        
    }

//Sid 
int diameter(TreeNode* root, int &h)
    {
        if(root == NULL)
            return 0;
        int lh = 0, rh = 0;
        int ld = diameter(root->left, lh);
        int rd = diameter(root->right, rh);
        h = max(lh, rh) + 1;
        return max(lh+rh, max(ld, rd));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = 0;
        return diameter(root, h);
    }
