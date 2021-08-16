// Hari

// void helper(TreeNode* root, vector<int> &res){ //Recursive
    //     if(root == nullptr) return;
    //     res.push_back(root->val);
    //     helper(root->left, res);
    //     helper(root->right, res);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        // Recursive
        // vector<int> res;
        // helper(root, res);
        // return res;
        
        //Iterative
        stack<TreeNode* > s;
        vector<int> res;
        if(root == nullptr) return res;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top(); 
            res.push_back(curr->val);
            s.pop();
            // Push right first then left as stack is LIFO
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
        return res;
    }
