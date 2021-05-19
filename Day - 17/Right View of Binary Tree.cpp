// Hari

vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode* > q;
        if(root == nullptr) return res;
        q.push(root);
        while(!q.empty()){
            int N = q.size();
            for(int i = 1; i<=N; i++){
                TreeNode* curr = q.front(); q.pop();
                if(i == N) res.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return res;
    }
