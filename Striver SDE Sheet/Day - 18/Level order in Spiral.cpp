// Hari

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        
        bool reverse = false; // reverse the vector if true
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int N = q.size();
            vector<int> currlvl(N, 0);
            for(int i = 0; i<N; i++){
                //iterate current level
                TreeNode* curr = q.front(); q.pop();
                
                if(!reverse) currlvl[i] = curr->val;
                else {
                    currlvl[N-i-1] = curr->val; // adding from behind
                }  
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(currlvl);  
            reverse = !reverse; // for next level, negate it       
        }
        return res;
    }
