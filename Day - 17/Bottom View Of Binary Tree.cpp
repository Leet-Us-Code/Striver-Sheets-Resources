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