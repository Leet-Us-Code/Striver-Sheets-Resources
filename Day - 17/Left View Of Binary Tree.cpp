//Function to return a list containing elements of left view of the binary tree.
void helper(Node *root, int level, int &maxLevel, vector<int> &res)
{
    if(root == NULL)
    return;
    if(level > maxLevel)
    {
        maxLevel = level;
        res.push_back(root->data);
    }
    helper(root->left, level+1, maxLevel, res);
    helper(root->right, level+1, maxLevel, res);
}
vector<int> leftView(Node *root)
{
   vector<int> res;
   int level = 0, maxLevel = INT_MIN;
   helper(root, level, maxLevel, res);
   return res;
}