// Hari

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	// We will do this using Prim's Algorithm
	// adj[i].first is the adj node and second is weight
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // O(N^2) uses array traversal to find min key everytime.
        // N*logN uses minheap (priority Q) to pick up min key in logN time. We will do this
        
        /* we need 3 arrays: 
        key[] to maintain the weight used to reach that node. Source node has 0
        mst[] to maintain if node already visited or not
        parent[] to note down parent node of each node. Source node has -1 
        
        When picking a min val from key[] check if its not visited (mst[])
        
        */
        
        int key[V]; bool mst[V]; int parent[V];
        
        // init
        for(int i = 0; i<V; i++){
            key[i] = INT_MAX;
            mst[i] = false;
            parent[i] = -1;
        }
        
        key[0] = 0; parent[0] = -1;
        // priority Q has key[i] value and index as pair
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,0}); // 0 val for 0th index
        
        // do it n-1 times as a MST with n nodes has n-1 edges
        for(int cnt = 0; cnt < V-1; cnt++){
            int u = pq.top().second; // this gives node with min key[i] val automatically
            pq.pop();
            mst[u] = true; //visited
            
            for(auto it: adj[u]){
                int v = it[0];
                int wt = it[1];
                if(mst[v] == false && wt < key[v]) {
                    // update key with new weight (prev it was high (either inf or some big no))
                    // and then update parent as u. mst[] changes only when node picked
                    key[v] = wt;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
            
        }
        
        // traverse key[i] and keep summing to get final wt of MST graph
        int sum = 0;
        for(int i = 0; i<V; i++){
            sum += key[i];
        }
        return sum;
    }
};
