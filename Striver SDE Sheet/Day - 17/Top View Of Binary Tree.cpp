// Hari

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // first element you get for a particular vertical level is the element u see from top
        map<int,int> m; // level and corresp element
        /*
        -2 -1 0 1 2 are the vertical levels. 
        If element is in a level and current val for that level is 0, then add this element to
        that level. Else, that element is not visible at that level. So, continue
        */
        queue<pair<Node*, int>> q; // Element and corresp. height
        vector<int> res;
        if(!root) return res;
        q.push({root, 0}); 
        while(!q.empty()){
            Node* curr = q.front().first;
            int currht = q.front().second;
            q.pop();
            if(!m[currht]) m[currht] = curr->data; // if val for this currht already exists, continue
            if(curr->left) q.push({curr->left, currht-1});
            if(curr->right) q.push({curr->right, currht+1});
        }
        // our map m has all the elements visible from top at each vertical level
        for(auto t: m){
            res.push_back(t.second);
        }
        return res;
        
    }

};

// Sid

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
