// Hari

// Method - 1 larger space using code O(m*n) SC
int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> sumMat(m, vector<int>(n, grid[0][0]));
        // find sum val for first row and col
        for(int i = 1; i<m; i++) sumMat[i][0] = sumMat[i-1][0] + grid[i][0];
        for(int j = 1; j<n; j++) sumMat[0][j] = sumMat[0][j-1] + grid[0][j];
        
        // now find the minval from top and left (as path can move down and right resp)
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                sumMat[i][j] = min(sumMat[i-1][j], sumMat[i][j-1]) + grid[i][j];
            }
        }
        
        return sumMat[m-1][n-1]; // last row last col element in bottom right will have final minSumPath val
    }

// Method - 2 
