// Hari

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> ans;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr == NULL){
                res.emplace_back(ans);
                ans.resize(0);
                if(q.size() > 0) q.push(NULL);
            }
            else {
                ans.emplace_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return res;
    }
};
