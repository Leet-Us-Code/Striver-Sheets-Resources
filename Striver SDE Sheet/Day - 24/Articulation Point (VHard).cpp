// Hari

#include <bits/stdc++.h>
using namespace std;

// Articulation points are points that if you remove them, the graph breaks. We will do DFS here to find # of bridges 
// We use 2 arrays tin[] (time of insertion) and low[] (smallest time in adj nodes of curr)
// Once dfs(it) trav is finished, we try to update its low[] and then check condition low[it] >= tin[node] (notice = sign this time)
// If condt true, then that node is a art point. 
// low[node] is either time of insertion (assigned at start) or lowest time of insertion across adj nodes

// parent != -1 check is done to ensure that normally the src vertex is not added as art point 
// But, if the src vertex has > 1 children (DFS is called for each child and not like DFS called for 1 child and rest get covered also) then src vertex is art point 
// IMPLEMENTATION VVV SIMILAR TO BRIDGES CODE 


void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isartPoint){
    vis[node] = 1;
    tin[node] = low[node] = timer++; // first dfs traversal both arrays get same val 
    
    int child = 0; // for deciding if src node should be artPoint or not 
    for(auto it: adj[node]){
        if(it == parent) continue; // dont want to go back in dfs. We want forward progress 
        
        if(!vis[it]){
            dfs(it, node, vis, tin, low, timer, adj, isartPoint);
            // after dfs calls over, we update low 
            low[node] = min(low[node], low[it]);
            child++;
            // bridges condition check (notice >= not > ). 
            if(low[it] >= tin[node] && parent != -1) isartPoint[node] = 1;
            // hasharray isartPoint used as sometimes same vertex is calc. to be art point multiple times. So to avoid repetition
        } else {
            // already visited. Just update low. Bridge cant exist as its already visited without 
            // going thru bridge 
            low[node] = min(low[node], tin[it]);
        }
        
    }
    
    if(parent == -1 && child > 1) isartPoint[node] = 1;
    // if its starting (src) node and > 1 children then it is art point 

}



int main() {
	int N, m;
	cin >> N >> m;
	vector<int> adj[N];
	// creating the graph from user input 
	for(int i = 0; i<m; i++){
	    int u,v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	
	vector<int> tin(N, -1);
	vector<int> low(N, -1);
	vector<int> vis(N, 0); // for dfs 
	vector<int> isartPoint(N, 0);
	int timer = 0;
	
	for(int i = 0; i<N; i++){ // standard dfs for all nodes 
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj, isartPoint);
	    }
	}
	
	// printing all the art points 
	for(int i = 0; i<N; i++){
	    if(isartPoint[i] == 1) cout << i << " ";
	}
	
	return 0; 
}
