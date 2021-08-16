// Hari

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // we use stack to keep conteact of last node added. This way, no need to
        //start from root again and again to comapre each element
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);
        
        for(int i = 1; i<preorder.size(); i++){
            TreeNode* curr = s.top();
            if(curr->val > preorder[i]){
                // add this preorder element to left of root (curr)
                TreeNode* newNode = new TreeNode(preorder[i]);
                curr->left = newNode;
                s.push(newNode);
            } else {
                // if predorder element is > than curr root, it may be greater than root of curr root also. Check it, and when this condt fails add it there
                while(!s.empty() && s.top()->val < preorder[i]){
                    curr = s.top(); s.pop();
                }
                // when preorder ele less than a stack ele and comes out of while,
                // the curr will show last node which can host preorder ele in right
                
                TreeNode* newNode = new TreeNode(preorder[i]);
                curr->right = newNode;
                s.push(newNode);
            }
        }
        return root;
    }
};

//Sid
class Solution {
public:
    TreeNode *helper(ListNode *start, ListNode *end)
    {
        if(start == end)
        {
            return NULL;
        }
        if(start->next == end)
        {
            TreeNode *root =  new TreeNode(start->val);
            return root;
        }
        ListNode *slow = start, *fast = start;
        while(fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = helper(start, slow);
        root->right = helper(slow->next, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *start = head, *end = NULL;
        return helper(start, end);
    }
};
