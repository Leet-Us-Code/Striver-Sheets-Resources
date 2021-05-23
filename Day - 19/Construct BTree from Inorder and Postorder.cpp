// Slight modification of Inorder and Preorder. Traverse from back instead of front as it is postorder

// Hari

class Solution {
public:
    int idx = 0;
    unordered_map<int, int> m;
    
    TreeNode* helper(vector<int>inorder, vector<int>postorder, int start, int end, int &idx){
        if(start > end || idx < 0) return nullptr;
        TreeNode* curr = new TreeNode(postorder[idx--]);
        // for leaf node
        if(start == end) return curr;
        // search this element in inorder
        int mid = m[curr->val]; //gives the index of curr
        //recursive calls
        curr->right = helper(inorder, postorder, mid+1, end, idx);
        curr->left = helper(inorder, postorder, start, mid-1, idx);
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // postorder gives us the parent each time when coming from back. 
        //Search this parent in inorder using map O(1)
        // and left of this in left subtree, right in right subtree
        int N = inorder.size();
        idx = N-1;
        m.clear();
        // filling map using inorder elements
        for(int i = 0; i<N; i++) m[inorder[i]] = i; // quick element index retrieval
        TreeNode* root = helper(inorder, postorder, 0, N-1, idx);
        return root;  
    }
};
