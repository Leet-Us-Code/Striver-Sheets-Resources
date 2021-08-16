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

//Sid 
int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh)+1;
    }
    void helper(TreeNode *root, int level, vector<int> &res)
    {
        if(root == NULL)
            return;
        if(level == 0)
        {
            res.push_back(root->val);
            return;
        }
        helper(root->left, level-1, res);
        helper(root->right, level-1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> x;
        int h = height(root);
        for(int i = 0; i < h; i++)
        {
            vector<int> temp;
            helper(root, i, temp);
            x.push_back(temp);
        }
        return x;
    }
