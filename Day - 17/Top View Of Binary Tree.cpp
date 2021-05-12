class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> mp;
        //we ll be doing level order traversal and updating the horizontal distances from  the root 
        queue<int> q1; // queue to store the horizontal distances of nodes from root 
        queue<Node*> q2;//queue to store the nodes from the root 
        q2.push(root);
        q1.push(0);
        while(!q1.empty() && !q2.empty())
        {
            Node *cur = q2.front();
            int dist = q1.front();
            q1.pop();
            q2.pop();
            if(mp.count(dist) == 0)
            {
                //if the distance hasnt been encountered yet then add it as it means it's the first occurrence 
                mp[dist] = cur->data;
            }
            if(cur->left != NULL)
            {
                q2.push(cur->left);
                q1.push(dist-1);
            }
            if(cur->right != NULL)
            {
                q2.push(cur->right);
                q1.push(dist+1);
            }
            
        }
        vector<int> res;
        map<int, int>::iterator it;
        for(it = mp.begin(); it != mp.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }

};