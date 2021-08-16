// Hari

// void helper(TreeNode* root, vector<int> &res){ // Recursive
    //     if(root == nullptr) return;
    //     helper(root->left, res);
    //     helper(root->right, res);
    //     res.push_back(root->val);
    // }
    
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> res;  // Recursive
        // helper(root, res);
        // return res;
        
        // Iterative
        stack<TreeNode* > s;
        vector<int> res;
        if(root == nullptr) return res;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();
            res.push_back(curr->val); s.pop();
            // In Postorder it is left->right->root. The reverse of this is root->right->left...which is a partial reverse of Preorder(root->left->right)
// So in preorder we pushed right to stack and then left. Here, do the opposite
            if(curr->left) s.push(curr->left);
            if(curr->right) s.push(curr->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
