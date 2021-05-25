// Hari

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // base condition 
    if (!root)  return ;
 
    // target node found
    if (root->key == key)
    {
        if (root->left)
        {
            Node* curr = root->left; // inorder predecessor
            while (curr->right) // rightmost node in left subT
                curr = curr->right;
            pre = curr ;
        }
 
        if (root->right)
        {
            Node* curr = root->right ; // inorder successor
            while (curr->left) // leftmost node in right subT
                curr = curr->left ;
            suc = curr ;
        }
        return ;
    }
 
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else 
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}
