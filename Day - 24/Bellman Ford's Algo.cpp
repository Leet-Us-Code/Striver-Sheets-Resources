// Hari

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // edges[i][0,1,2] = u,v, weight respectively
	    // get dist array
	    int INF = 1e9+7;
	    vector<int> dist(n, INF);
	    dist[0] = 0; //source
	    
	    for(int i = 1; i<=n-1; i++){ // relaxation for n-1 times
	        for(auto it: edges){
	            if(dist[it[0]] + it[2] < dist[it[1]]){
	                dist[it[1]] = dist[it[0]] + it[2];
	            }
	        }
	    }
	    
	    // try relaxing once more. If any dist val changes then -ve cycle exists
	    int res = 0;
	    for(auto it: edges){
	        if(dist[it[0]] + it[2] < dist[it[1]]){
	           res = 1;
	           return res;
	    }
	}
	
	return res;
};
