// Hari

class Solution {
public:
    bool helper(TreeNode* root, unordered_set<int> &s, int k){
        if(!root) return false;
        if(s.find(k-root->val) != s.end()) return true;
        s.insert(root->val);
        return helper(root->left, s, k) || helper(root->right, s, k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root, s, k);
    }
};
