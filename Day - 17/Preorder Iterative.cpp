/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
        {
            return res;
        }
        
        stack<TreeNode*> s;
        s.push(root);
        while(s.size() > 0)
        {
            TreeNode *cur = s.top();
            res.push_back(cur->val);
            s.pop();
            if(cur->right != NULL)
            s.push(cur->right);
            if(cur->left != NULL)
            s.push(cur->left);
        }
        return res;
    }
};