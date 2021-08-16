// Hari

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right) return root; // if both l and r exist for a node, that node is the LCA. If one of them is null, just pass the non null val up so that the LCA can be found in the future above.
        if(left) return left;
        else return right;        
    }
};


//Sid 
bool nodeToRoot(TreeNode* root, vector<TreeNode*> &path, TreeNode *x)
    {
        if(root == NULL)
            return false;
        if(root == x)
        {
            path.push_back(root);
            return true;
        }
        bool l = nodeToRoot(root->left, path, x);
        if(l)
        {
            path.push_back(root);
            return true;
        }
        bool r = nodeToRoot(root->right, path, x);
        if(r)
        {
            path.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        bool e1 = nodeToRoot(root, path1, p);
        bool e2 = nodeToRoot(root, path2, q);
        int i = 0, j = 0;
        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());
        while(i < path1.size() && j < path2.size())
        {
            if(path1[i] == path2[j])
            {
                i++;
                j++;
            }
            else
                break;
        }
        return path1[i-1];
    }
