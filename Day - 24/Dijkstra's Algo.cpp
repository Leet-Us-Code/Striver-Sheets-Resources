// Hari

#include <bits/stdc++>
using namespace std;
// Implementing dijkstra algo for single source shortest path using DFS and Priority Q (minHeap)
// minHeap ensures only min distance node chosen as source. So even if same node has 2 dist vals in minH 
// the smaller wt one will be chosen. The other one will also be checked, but will 100% not give better result
int main() {
	// adj list has neighbour node and weight as pairs. minHeap has dist and "from" node ias pair 
	
	int n, m, source; // nodes and edges. We are creating the graph
	cin >> n >> m;
	vector<pair<int, int>> graph[n+1];
	
	int u,v,wt; // from node, to node and wt btw them
	for(int i = 0; i<m; i++){
	    cin >> u >> v >> wt;
	    graph[u].push_back({v,wt}); // graph[u].push_back(make_pair(v,wt));
	    graph[v].push_back({u,wt}); // both as undirected graph 
	}
	
	cin >> source; 
	
	// Dijkstra 
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> pq; // {dist, from}
	vector<int> dist(n+1, INT_MAX); // dist array for all nodes. Will hold all ans 
	
	dist[source] = 0; 
	pq.push(make_pair(0, source)); 
	
	while(!pq.empty()){
	    int dist = pq.top().first;
	    int prev = pq.top().second; pq.pop();
	    
	    // traverse its adj nodes 
	    for(auto it: graph[prev]){
	        int next = it.first; // "it->first" iff we used iterator like vector<pair<int,int>>::iterator it
	        int nextDist = it.second;
	        if(dist + nextDist < dist[next]) {
	            dist[next] = dist + nextDist;
	            pq.push(make_pair(dist[next], next)); 
	        }
	        
	    }
	    
	}
	
	// all min dist will be in dist vector 
	for(int i = 1; i<=n; i++){
	    cout << dist[i] << " ";
	}
	
	
	return 0;
}
