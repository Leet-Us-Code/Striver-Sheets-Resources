// Hari

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int V = matrix.size();
	    // all pairs shortest path
	    // we consider every node as intermediate btw the 2 pairs of nodes chosen and see if
	    // they can be reached w a smaller distance thru that intermediate k node
	    
	    for(int k = 0; k<V; k++){
	        for(int i = 0; i<V; i++){
	            for(int j = 0; j<V; j++){
	                // if intermediate k node cannot be used to access either/both nodes, ignore
	                if(matrix[i][k] == -1 || matrix[k][j] == -1) continue;
	                // if node not yet visited
	                else if(matrix[i][j] == -1) matrix[i][j] = matrix[i][k] + matrix[k][j];
	                else matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j] );
	            }
	        }
	    }
	    
	    // For checking -ve cycle. If self loop is negative then -ve cycle exists
	    // Just a little sanity check
	    for(int i = 0; i<V; i++){
	        if(matrix[i][i] < 0) cout << "-ve cycle";
	    }
	}
};
