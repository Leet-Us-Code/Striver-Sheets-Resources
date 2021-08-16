// Hari

// We can use Kahn's algo (used in Topological Sort BFS) here. That algo works only
// in DAG (directed acyclic (no cycle) graph). And topo sort is just linear ordering of 
// vertices. If vertex count doesn't match, then cycle exists in graph

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	queue<int> q;
	   	vector<int> indegree(V,0);
	   	
	   	// assign indegrees
	   	for(int i = 0; i<V; i++){
	   	    for(auto it: adj[i]) indegree[it]++;
	   	}
	   	
	   	// check for 0s
	   	for(int i = 0; i<V; i++){
	   	    if(indegree[i] == 0) q.push(i);
	   	}
	   	
	   	int count = 0;
	   	vector<int> res;
	   	while(!q.empty()){
	   	    int curr = q.front(); q.pop();
	   	    count++;
	   	    res.push_back(curr);
	   	    for(auto it: adj[curr]) {
	   	        indegree[it]--;
	   	        if(indegree[it] == 0) q.push(it);
	   	    }
	   	}
	   	
	   	if(count == V) return false; // no cycle
	   	return true;
	}
};
