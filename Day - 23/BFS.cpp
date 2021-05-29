// Hari

// When there are no unconnected components in graph, no need to have an upper for loop for checking each vertex

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    vector<int> bfs; 
	    vector<int> vis(V, 0);
	    queue<int> q; 
	    q.push(0); 
	    vis[0] = 1; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        bfs.push_back(node); 
	        
	        for(auto it : adj[node]) {
	            if(!vis[it]) {
	                q.push(it); 
	                vis[it] = 1; 
	            }
	        }
	    }
	    
	    return bfs; 
	}
};

// When there are some unconnected components in graph

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    vector<int> bfs; 
	    vector<int> vis(V+1, 0);
	    
	    for(int i = 0; i<V; i++){ // this loop ensures no node missed out in case of unconnected components
	        if(!vis[i]){
	            queue<int> q; 
	            q.push(i); 
	            vis[i] = 1; 
	            
	            while(!q.empty()) {
        	        int node = q.front();
        	        q.pop(); 
        	        bfs.push_back(node); 
        	        
        	        for(auto it : adj[node]) {
        	            if(!vis[it]) {
        	                q.push(it); 
        	                vis[it] = 1; 
        	            }
        	        }
	            }
	        }
	    }
	    
	    return bfs; 
	}
};
