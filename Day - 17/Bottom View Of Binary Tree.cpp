// Hari

// Refer Top view before this. Exact same method. There, we add the first element that is in a level and then don't change it. Here, we keep updating elements in each lvl
// as we traverse..so at each lvl the last element that came at that level is present

//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
{
        // last element you get for a particular vertical level is the element u see from bottom
        map<int,int> m; // level and corresp element
        /*
        -2 -1 0 1 2 are the vertical levels. 
        */
        queue<pair<Node*, int>> q; // Element and corresp. height
        vector<int> res;
        if(!root) return res;
        q.push({root, 0}); 
        while(!q.empty()){
            Node* curr = q.front().first;
            int currht = q.front().second;
            q.pop();
            m[currht] = curr->data; // if val for this currht already exists, continue
            if(curr->left) q.push({curr->left, currht-1});
            if(curr->right) q.push({curr->right, currht+1});
        }
        // our map m has all the elements visible from top at each vertical level
        for(auto t: m){
            res.push_back(t.second);
        }
        return res;
}

// Sid
//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
{
   vector<int> res;
   map<int, int> mp;
   queue<Node*> q1;
   queue<int> q2;
   q1.push(root);
   q2.push(0);
   while(!q1.empty() && !q2.empty())
   {
       Node *cur = q1.front();
       int dist = q2.front();
       q1.pop();
       q2.pop();
       mp[dist] = cur->data;
       if(cur->left != NULL)
       {
           q1.push(cur->left);
           q2.push(dist-1);
       }
       if(cur->right != NULL)
       {
           q1.push(cur->right);
           q2.push(dist+1);
       }
   }
   map<int, int>:: iterator it;
   for(it = mp.begin(); it != mp.end(); it++)
   {
       res.push_back(it->second);
   }
   return res;
}
