// Hari

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	// Step 1: Sort all vertices by order of finishing time ie. Topological sort
	// Step 2: Transpose (reverse dirn of all edges) the graph
	// Step 3: Do DFS on this transposed graph in order of stack.pop() from Step 1
	void dfs(int curr, stack<int> &stk, vector<int> &vis, vector<int> adj[]){
	    vis[curr] = 1;
	    
	    for(auto it: adj[curr]){
	        if(!vis[it]) dfs(it, stk, vis, adj);
	    }
	    
	    stk.push(curr);
	}
	
	void revDfs(int curr, vector<int> &vis, vector<int> adj[]){
	    vis[curr] = 1;
	    
	    for(auto it: adj[curr]){
	        if(!vis[it]) revDfs(it, vis, adj);
	    }
	}
	
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        // do topo sort first
        stack<int> stk;
        int res = 0;
        vector<int> vis(V, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i]) dfs(i, stk, vis, adj);
        }
        
        // now transpose
        
        vector<int> transpose[V];
        
        for(int i = 0; i<V; i++){
            vis[i] = 0; // reset status of vis for step 3 (DFS)
            for(auto it: adj[i]){
                transpose[it].push_back(i); // reverse graph is in "transpose" vector
            }
        }
        
        // Now do dfs with transpose
        // for dfs, we use stack created in step 1
        while(!stk.empty()){
            int node = stk.top(); stk.pop();
            if(!vis[node]){
                revDfs(node, vis, adj);
                res++;
            }
        }
        return res;
    }
};
