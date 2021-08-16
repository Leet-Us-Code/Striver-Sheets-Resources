// Hari

class Solution
{   
    public:
    bool chkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]){
        vis[node] = 1; dfsVis[node] = 1;
        for(auto it: adj[node]) {
            // dfs
            if(!vis[it]){
                // not visited. Go to its child and then its child and so on.
                // If any 1 of the node is found to have cycle, then return 
                // true through all recursions and then pass that true to isCyclic
                if(chkCycle(it, adj, vis, dfsVis)) return true;
            } else {
                // node is visited. If it is not visited in dfsVis then no probs,
                // as the node has been visited before but not on this traversal.
                if(dfsVis[it] == 1) return true;
            }
        }
        // after this node traversal is over and there are no more adj nodes for it, make its dfsVis 0. vis will NOT change
        dfsVis[node] = 0;
        return false; // pass this value higher recursive levels
    }
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// we have 2 arrays instead of 1 to keep track of visited.
	   	// vis is for all the nodes overall, and dfsVis is for 
	   	// maintaining visited nodes in this current iteration only. 
	   	int vis[V], dfsVis[V];
	   	memset(vis, 0, sizeof vis);
	   	memset(dfsVis, 0, sizeof dfsVis);
	   	
	   	for(int i = 0; i<V; i++){
	   	    if(!vis[i]){
	   	        if(chkCycle(i, adj, vis, dfsVis)) return true; //cycle exists
	   	    }
	   	}
	   	return false;
	}
};
