// Hari

class Solution {
public:
    int idx = 0;
    unordered_map<int, int> m;
    
    TreeNode* helper(vector<int>preorder, vector<int>inorder, int start, int end){
        // traverse preorder
        if(start > end) return nullptr; // base case
        TreeNode* curr = new TreeNode(preorder[idx++]);
        if(start == end) return curr; // when leaf node added
        int mid = m[curr->val]; // get parent index.
        curr->left = helper(preorder, inorder, start, mid-1);
        curr->right = helper(preorder, inorder, mid+1, end);        
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder gives us the parent each time. Search this parent in inorder 
        // (using map O(1)) and left of this in left subtree, right in right subtree
        idx = 0;
        m.clear();
        int N = inorder.size();
        // filling map using inorder elements
        for(int i = 0; i<N; i++) m[inorder[i]] = i; // quick element index retrieval
        TreeNode* root = helper(preorder, inorder, 0, N-1);
        return root;  
        
    }
};
