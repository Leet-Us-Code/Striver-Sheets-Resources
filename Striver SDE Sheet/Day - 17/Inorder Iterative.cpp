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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* x = root;
        while(x != NULL || s.size() > 0)
        {
            while(x != NULL)
            {
                s.push(x);
                x = x->left;
            }
            x = s.top();
            s.pop();
            res.push_back(x->val);
            x = x->right;
        }
        return res;
    }
};