// Hari

int maxDepth(TreeNode* root) {
//         if(root == nullptr) return 0; //base case when we reach a leaf
        
//         int left = maxDepth(root->left);
//         int right = maxDepth(root->right);
        
//         return max(left, right) + 1; // add curr level also
        // Exact thing but in 1 line
return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
