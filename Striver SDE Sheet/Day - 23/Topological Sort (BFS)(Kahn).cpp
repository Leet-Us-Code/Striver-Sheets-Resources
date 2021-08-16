// Hari

// Keep check of indegree of each node. Whichever ones have 0 as indegree, push then to Queue. Then pop out top of Q (and add this node to final ans vector), 
// check if it has adj nodes, and reduce their indegree by 1. If it becomes 0, push it to Q and so on. 

// In topo sort, if u->v edge exists in graph, in topo sort order u comes before v. Kahn's algo always starts from a vertex w indegree 0. As nodes are added to final ans,
// their adj node's dependency factor dec. by 1 and hence we subtract.

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> indegree(V,0);
	    //  add indegree values for all node
	    for(int i = 0; i<V; i++){
	        for(auto it: adj[i]) indegree[it]++; // i->it is edge so it's indegree += 1
	    }
	    
	    // whichever nodes have 0 indegree, add them to Q
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    // keep popping from Q, find adj nodes and dec their val
	    vector<int> res;
	    while(!q.empty()){
	        int curr = q.front(); q.pop();
	        res.push_back(curr);
	        
	        for(auto it: adj[curr]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    return res;
	}
};
