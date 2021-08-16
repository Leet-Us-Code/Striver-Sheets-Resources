// Hari

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // a NULL denotes the end of a particular level. Next level of BFS starts after a NULL
        
        vector<int> ans;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr == NULL){ // current level over
                res.emplace_back(ans); //push particular lvl vector to ans
                ans.resize(0); // same as ans.clear()
                if(q.size() > 0) q.push(NULL); // if next lvl elements are there add a NULL behind them
            }
            else {
                ans.emplace_back(curr->val); // emplace_back is a faster alternative to push_back
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return res;
    }
};
