// Same logic as "Size of largest BST in BT". Instead of keeping track of sum in BSTNode, I keep track of no. of elements

// Hari

class Solution {
public:
    // define a struct with parameters that keep check of whether BST exists
    // watch Tushar roy video on YT for explanation
    struct BSTNode {
        bool isBST;
        int min;
        int max;
        int sum; 
    };
    BSTNode helper(TreeNode* curr, int &ans){
        if(curr){
            BSTNode left = helper(curr->left, ans);
            BSTNode right = helper(curr->right, ans);
            // for a node's isBST to be true, its left and right subT should
            // also be BSTs, and node's val > left's max and <right's min
            bool isBST = left.isBST && right.isBST && curr->val > left.max && curr->val < right.min;
            // sum param of this particular node
            int sum = left.sum + right.sum + curr->val;
            // only if a BST can be formed at this curr will we modify ans
            if(isBST) ans = max(ans, sum);
            // return status to higher levels
            return {isBST, min(curr->val, left.min), max(curr->val, right.max), sum };               
        } else return {true, INT_MAX, INT_MIN, 0};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};
