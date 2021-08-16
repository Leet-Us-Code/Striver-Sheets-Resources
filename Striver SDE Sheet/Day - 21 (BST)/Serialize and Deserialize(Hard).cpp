// Hari

class Codec {
public:
    // Watch Back to Back SWE's vid for explanation
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#"; // null nodes get converted to # in string
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right); // preorder conversion to string separated by commas
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // take the string created in serialize and convert it back to BTree nodes
        if(data == "#") return nullptr;
        stringstream ss(data); // makes string operations easier. data is assigned to ss which is passed to helper function
        return desHelper(ss);
    }
    
    TreeNode* desHelper(stringstream &ss){
        string word;
        getline(ss,word,','); // each time we get a new element from stringstream to convert to node and add to BT. Delimiter is comma.
        if(word == "#") return nullptr;
        else {
            TreeNode* curr = new TreeNode(stoi(word));
            curr->left = desHelper(ss);
            curr->right = desHelper(ss);
            return curr;
        }
    }
};
