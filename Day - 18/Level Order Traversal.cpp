// Hari

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int N = q.size();
            vector<int> currlvl;
            for(int i = 0; i<N; i++){
                //iterate current level
                TreeNode* curr = q.front(); q.pop();
                currlvl.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(currlvl);           
        }
        return res;
    }
