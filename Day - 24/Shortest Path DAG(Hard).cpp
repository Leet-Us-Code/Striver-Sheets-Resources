// Hari

#include <bits/stdc++.h> 
#define INF INT_MAX 

using namespace std;

void findTopoSort(int node, int vis[], stack<int> &stk, vector<pair<int, int>> adj[]){
    // generate topo sort 
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it.first]) findTopoSort(it.first, vis, stk, adj);
    }
    stk.push(node);
}

void shortestPath(int src, int N, vector<pair<int, int>> adj[]){
    // same as "Shortest Path in  Undirected Graph" but we do topological sort first w stack 
    int vis[N] = {0}; // init the visited array 
    stack<int> stk; // when all children of a node traversed, put that node here
    
    for(int i = 0; i<N; i++){ // standard dfs
        if(!vis[i]) {
            findTopoSort(i, vis, stk, adj); 
        }
    }
    
    // init the distance array 
    int dist[N]; 
	for (int i = 0; i < N; i++) 
		dist[i] = 1e9;
    dist[src] = 0; // starting point has 0 dist 
    
    // after doing topo sort, pop stack ele one by one and calc their dist vector values as done in undirected graph 
    while(!stk.empty()){
        int curr = stk.top(); stk.pop();
        
        if(dist[curr] != INF) {
            // calc for its neighbors
            for(auto it: adj[curr]){
                if(dist[curr] + it.second < dist[it.first]) {
                    // if source dist + edge wt < dist at adj node 
                    dist[it.first] = dist[curr] + it.second;
                }
            }
        }
        
    }
    
    // print the final distances
    for(int i = 0; i<N; i++){
        (dist[i] == 1e9) ? cout << "INF" : cout << dist[i] << " ";
    }
    
}

int main() {
	int n, m; // n is no of nodes and m is no of edges
	cin >> n >> m;
	// in directed graph w weights, we use pair to store a node and its weight
	vector<pair<int, int>> adj[n];
	for(int i = 0; i<n; i++){
	    int u,v,wt;
	    cin >> u >> v >> wt; // u->v is an edge and wt is weight btw the 2 nodes
	    adj[u]. push_back({v,wt});
	}
	
	shortestPath(0, n, adj); // source, no of nodes, adj list 
	return 0;
}
