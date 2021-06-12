// Hari

#include <bits/stdc++.h>
using namespace std;

// Pick greedily the smallest wt node, and check if this node and its connection node share a parent 
// using Disjoint Set concept learnt prev. If same parent, then cycle would form. So edge not allowed. 

struct node { // we use a datastructure instead of adj-list to sort in asc. based on wt 
    int u;
    int v;
    int wt;
    //constructor
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b){
    return a.wt < b.wt;
}

int findParent(int u, vector<int> &parent){
    if(u == parent[u]) return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(u, parent);
    v = findParent(v, parent);
    
    if(rank[u] < rank[v]){
        // add u to v 
        parent[u] = v;
    } else if(rank[u] > rank[v]){
        // add v to u 
        parent[v] = u;
    }
    
    else {
        // btoh ranks same. 
        parent[u] =  v;
        rank[v]++;
    }
}


int main() {
	int N, m; // nodes and edges count 
	cin >> N >> m;
	vector<node> edges;
	for(int i = 0; i<m; i++){
	    int u,v,wt;
	    cin >> u >> v >> wt;
	    edges.push_back(node(u,v,wt));
	}
	
	// sorting by weight 
	sort(edges.begin(), edges.end(), comp); 
	
	// Disjoint set starts - parent and rank arrays 
	vector<int> parent(N);
	for(int i = 0; i<N; i++) parent[i] = i; // self loop 
	vector<int> rank(N, 0); 
	
	int cost = 0; // MST cost 
	vector<pair<int, int>> mst;
	for(auto it: edges){
	    // trying to connect it.u and it.v by checking if edge btw them is valid
	    if(findParent(it.u, parent) != findParent(it.v, parent)){
	        // valid
	        cost += it.wt;
	        mst.push_back({it.u, it.v}); // adding edge to MST 
	        unionn(it.u, it.v, parent, rank); // unionize these 2 diff components 
	    }
	}
	
	cout << cost << endl;
	// final MST
	for(auto it: mst){
	    cout << it.first << "--" << it.second << endl;
	}
	return 0;
	
}
