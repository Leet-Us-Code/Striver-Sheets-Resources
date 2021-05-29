// Hari

// No unconnected components left out
class Solution 
{
    public:
    void helper(int node, vector<int> &res, vector<int> &vis, vector<int> adj[]) {
        // add this unvisited node to res
        res.push_back(node);
        vis[node] = 1;
        // recursively call its neighbor, which will call its neighbor and so on
        // once calls are over, they trace back and see if any other unvisited
        // neighbor is there for an already visited node
        for(auto it: adj[node]){
            if(!vis[it]) helper(it, res, vis, adj);
        }
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	   vector<int> res;
	   vector<int> vis(V,0);
	   for(int i = 0; i<V; i++){ // ensures no unconnected node left out
	       if(!vis[i]) helper(i, res, vis, adj);
	   }
	   return res;
	}
};
