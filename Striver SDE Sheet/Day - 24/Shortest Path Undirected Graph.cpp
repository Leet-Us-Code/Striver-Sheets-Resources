// Hari

void shortestPathBFS(vector<int> adj[], int N, int src){
    // adj is adjacency list of graph, N is # of nodes, src is starting node from which we find min dist to all other nodes
    vector<int> dist(N,1000); // initializing dist for all nodes with a big no (INT_MAX). Here, 1000 arbitrarity chosen
    queue<int> q;
    
    dist[src] = 0;
    q.push(src);
    
    while(!q.empty()){
        int curr = q.front(); q.pop();
        
        for(auto it: adj[curr]){
            if(dist[curr] + 1 < dist[it]) {
                dist[it] = dist[curr] + 1;
                q.push(it);
            }
        }
    }
    
    for(int i = 0; i<N; i++){
        cout << dist[i] << " ";
    }
    
}
