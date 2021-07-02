// Hari

// Ditto unbounded knapsack, just rephrased

// Method - 1 using 2D DP table

int maximizeTheCuts(int n, int x, int y, int z)
    {
        // this is knapsack except x,y,z are denominations and we need max no of coins 
        int dp[3+1][n+1];
        int cuts[] = {x, y, z};
        // rows are the cut lengths and cols are the current length of rod chosen
        for(int i = 0; i<=3; i++) {
            for(int j = 0; j<=n; j++) {
                // first row is INT_MIN , first col = 0 as per knapsack concept
                // with cut len = 0 (row) infinite cuts can be made. Assume minimum infinity so that we can find max val cut (INT_MIN)
                // we can make 0 cuts in rod length 0 with x,y,z cut lengths (0)
                
                if(i == 0 || j == 0) {
                    if(i == 0) dp[0][j] = INT_MIN;
                    else dp[i][0] = 0;
                }
                
                else {
                    if(cuts[i-1] > j) dp[i][j] = dp[i-1][j];
                    else {
                        // cuts[i-1] <= j
                        dp[i][j] = max(dp[i-1][j], 1 + dp[i][j - cuts[i-1]]);  // new cut count 
                    }
                }
            }
        }
        
        return dp[3][n] < 0 ? 0 : dp[3][n];
    }

// Method - 2 using 1D array

int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        memset(dp, -1, sizeof dp);
        
        dp[0] = 0;
        
        for(int i = 1; i<=n; i++) {
            if(i - x >= 0) {
                dp[i] = max(dp[i], dp[i - x]);
            }
            
            if(i - y >= 0) {
                dp[i] = max(dp[i], dp[i - y]);
            }
            
            if(i - z >= 0) {
                dp[i] = max(dp[i], dp[i - z]);
            }
            
            // if one of the above has occured, inc count of cut by 1
            if(dp[i] != -1) dp[i] += 1;
        }
        
        return max(0, dp[n]);
        // same as return dp[n] == -1 ? 0 : dp[n];
    }
