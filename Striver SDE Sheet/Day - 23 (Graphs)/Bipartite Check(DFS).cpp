// Hari

class Solution {
    // If an odd-no. cycle exists in graph, it cannot be bipartite. 
public:
    bool helper(int node, vector<int> adj[], int color[]){
        if(color[node] == -1) color[node] = 1;
        // Same logic as BFS. There we used Queue, here we just keep recursing 
        // and exploring each node and constantly checking the color
        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                if(!helper(it, adj, color)) return false;
            } else {
                if(color[it] == color[node]) return false;
            }
        }
        return true;
    }

    
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V]; // maintains color of nodes (0 or 1 are the available colors)
	    memset(color, -1, sizeof(color)); // initial assignment
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1){
	            if(!helper(i, adj, color)) return false;
	            // even if 1 node fails, it is not bi-partite
	        }
	    }
	    return true;
	}

};
