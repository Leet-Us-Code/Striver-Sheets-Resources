// Hari

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int kLarge = 0, c = 0;
    void helper(Node *root, int K){
        if(!root || c >= K) return;
        // go right then left (reverse inorder)
        helper(root->right, K);
        c++;
        if(c == K){
            kLarge = root->data;
            return;
        }
        // now go left
        return helper(root->left, K);
    }
    int kthLargest(Node *root, int K)
    {
        helper(root, K);
        return kLarge;
    }
};
