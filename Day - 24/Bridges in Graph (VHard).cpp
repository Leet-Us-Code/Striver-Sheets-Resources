// Hari

#include <bits/stdc++.h>
using namespace std;

// Bridges are edges that if you remove them, the graph breaks. We will do DFS here to find # of bridges 
// We use 2 arrays tin[] (time of insertion) and low[] (smallest time in adj nodes of curr)
// Once dfs(it) trav is finished, we try to update its low[] and then check condition low[it] > tin[node]
// If condt true, then that edge is a bridge. 
// low[node] is either time of insertion (assigned at start) or lowest time of insertion across adj nodes
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]){
    vis[node] = 1;
    tin[node] = low[node] = timer++; // first dfs traversal both arrays get same val 
    
    for(auto it: adj[node]){
        if(it == parent) continue; // dont want to go back in dfs. We want forward progress 
        
        if(!vis[it]){
            dfs(it, node, vis, tin, low, timer, adj);
            // after dfs calls over, we update low 
            low[node] = min(low[node], low[it]);
            
            // bridges condition check - if low[it] is lesser, then the other way (not edge removed) can reach node easier. 
            if(low[it] > tin[node]) cout << node << "--" << it << "is a bridge" << endl;
        } else {
            // already visited. Just update low. Bridge cant exist as its already visited without 
            // going thru bridge 
            low[node] = min(low[node], tin[it]);
        }
        
    }
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
	int timer = 0;
	
	for(int i = 0; i<N; i++){ // standard dfs for all nodes 
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj);
	    }
	}
	
	return 0; 
}
