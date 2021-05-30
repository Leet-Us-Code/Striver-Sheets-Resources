// Hari

class Solution 
{   
    public:
    bool cycleChk(int node, int parent, vector<int>adj[], vector<int> &vis){
        // We use DFS this time. If a node is found to be already visited 
        // and it is NOT the parent of our current node, then it has already been
        // traversed and hence is a cycle
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(cycleChk(it, node, adj, vis)) return true;
                // as DFS keeps going down, if any iteration gives a True, return
                // true. No need to keep going down in DFS further
            } else {
                if(it != parent) return true;
            }
        }
        return false;
    }
  //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V+1,0);
	    for(int i = 0; i<V; i++){
	        if(!vis[i]) {
	            if(cycleChk(i, -1, adj, vis)) return true; // if cycle found
	        }
	    }
	    return false;
	}
};
