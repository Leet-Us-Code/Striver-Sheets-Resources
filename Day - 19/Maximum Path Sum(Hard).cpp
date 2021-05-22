// Hari

class Solution {
    // Best explanation: https://www.youtube.com/watch?v=6cA_NDtpyz8&ab_channel=MichaelMuinosMichaelMuinos
public:
    int maxP = INT_MIN; 
    
    int helper(TreeNode* curr){
        // do postorder traversal standard
        if(curr == nullptr) return 0;
        
        //If result is -ve val, we won't send this val to curr. Send 0 instead
        int left = max(0,helper(curr->left));
        int right = max(0,helper(curr->right));
        // when coming out of recursive calls we find new maxP 
        
        maxP = max(maxP, left + right + curr->val);
        // maxP gets compared, updated with maxP value of curr's subtrees 
        
        return max(left, right) + curr->val;
        // Return value will be used to check maxP considering tree's main root in path. 
        
    }
    
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxP;
    }
};
