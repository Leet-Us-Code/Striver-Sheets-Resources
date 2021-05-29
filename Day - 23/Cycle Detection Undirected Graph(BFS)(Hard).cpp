// Hari

class Solution 
{   
    public:
    bool cycleChk(int node, int V, vector<int>adj[], vector<int> &vis){
        // We use BFS this time. If a node is found to be already visited 
        // and it is NOT the parent of our current node, then it has already been
        // traversed and hence is a cycle
        queue<pair<int, int>> q;
        vis[node] = 1;
        q.push({node, -1}); // initial node won't have parent
        
        while(!q.empty()){
            int node = q.front(). first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node}); 
                } else {
                    // "it" node has been traversed already
                    if(parent != it) return true;
                }
            }
        }
        return false;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    for(int i = 0; i<V; i++){
	        if(!vis[i]) {
	            if(cycleChk(i, V, adj, vis)) return true; // if cycle found
	        }
	    }
	    return false;
	}
};
