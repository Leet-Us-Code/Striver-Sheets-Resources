// Hari

class Solution
{
	public:
	void helper(int node, vector<int> &vis, stack<int> &s, vector<int> adj[]){
	    vis[node] = 1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it])
	            helper(it, vis, s, adj);
	    }
	    s.push(node);
	} 
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> s;
	    // after traversing a node when there is not adj node left, add that node into 
	    // stack. So always child is added first and then parent. So whe popping out
	    // from stack, parent comes before child in topologicl sort sequence
	    vector<int> vis(V,0);
	    for(int i = 0; i<V; i++){
	        if(!vis[i]) helper(i, vis, s, adj);
	    }
	    // pop from stack
	    vector<int> res;
	    while(!s.empty()){
	        res.push_back(s.top()); s.pop();
	    }
	    return res;
	}
};
