// Hari

void helper(TreeNode* root, vector<int> &res){ // Recursive
        if(root == nullptr) return;
        else {
            helper(root->left, res);
            res.push_back(root->val);
            helper(root->right, res);
        }
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        // Iterative
//         stack<TreeNode *> s;
//         vector<int> res;
//         TreeNode* curr = root;
        
//         while(curr != NULL || !s.empty()){
//             while(curr != NULL){
//                 s.push(curr);
//                 curr = curr->left;
//             }
//             // when NULL is reached
//             curr = s.top();
//             res.emplace_back(curr->val);
//             curr = curr->right;
//             s.pop();
//         }
//         return res;
        
        // Recursive
        vector<int> res;
        helper(root, res);
        return res;
    }
