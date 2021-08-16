// Hari

void helper(Node* root, int key, int& floor, int& ceil)
{
 
    while (root) {
        // when the key itself is found, it is both the floor and ceil.
        if (root->data == key) {
            ceil = root->data;
            floor = root->data;
            return;
        }
        // if root < key, root is the floor (first smallest val) and ceil is somewhere in right subT
        if (key > root->data) {
            floor = root->data;
            root = root->right;
        }
        else {  // converse
            ceil = root->data;
            root = root->left;
        }
    }
    return;
}
