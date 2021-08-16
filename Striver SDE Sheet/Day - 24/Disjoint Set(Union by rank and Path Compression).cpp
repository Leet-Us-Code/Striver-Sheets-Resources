// Hari

#include<bits/stdc++.h>
using namespace std;

// Disjoint Sets help cluster nodes together. Used in Kruskal's Algo. 

int parent[10000];
int rank[10000];

void makeSet(int N) {
    // for all N nodes, it makes their parent as themselves (self loop) and init rank to be 0 
    // rank is the ht of the tree formed from that node to the leaf. It inc in val by 1 iff 
    // both nodes ranks are equal. Rank helps figure out which graph cluster is smaller, so that this
    // small tree is added to the bigger tree (higher rank) to ensure ht doesnt inc. If viceversa is done
    // then ht of final graph/tree increases
    
    for(int i = 0; i<=N; i++){
        parent[i] = i;
        rank[i] = 0; 
    }
}

void findParent(int node){   // TC -> O(4*alpha) which is const time for each node 
    // Finds the parent node of a node. 
    // 2->3->5 is tree. findParent(5) goes to 3 and then 2 and then 2 (self loop)
    if(node == parent[node]) return node; // once self loop happens that is the parent(2) of node(5)
    
    return parent[node] = findParent(parent[node]); // keep assigning parent as u go up the tree. So next time 
    // findParent(5) is called, it will just return 2 instead of going from 5 -> 3 -> 2 -> 2. 
    // This is called PATH COMPRESSION
}

void union(int u, int v){
    // cluster u and v together and assign one of them as parent
    u = findParent(u);
    v = findParent(v);
    
    if(rank[u] < rank[v]) {
        // u is smaller. Attach u to v. Read comment in makeSet()
        parent[u] = v;
    } else if(rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        // both rank equal. v can attach to u, and vice versa is also fine. But don't forget to inc rank
        // as depth of tree will inc in this case 
        parent[v] = u; // Attach v to u. 
        rank[u]++; // u's rank inc by 1
    }
}

void main() {
	makeSet(50);
	int m; // user gives m operations 
	// eg. union(1,2), union(2,3), union(4,5) etc 
	cin >> m;
	while(m--){
	    int u, v; 
	    cin >> u >> v;
	    union(u,v);
	}
	
	// find if nodes 2 and 3 (assume exists) belong to same component or not 
	if(findParent(2) != findParent(3)) cout << "Diff components";
	else cout << "Both part of same component";
	
	
}

