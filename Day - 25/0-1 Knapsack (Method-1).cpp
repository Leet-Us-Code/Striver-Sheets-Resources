// TC and SC : O(m*n) as 2D matrix is used

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // we will do bottom up appoach using 2D matrix 
       int dp[n+1][w+1];
       memset(dp, 0, sizeof dp); 
       // rows are value chosen and columns are weights. For each value (row) we will calc 
       // all values (subproblems). So, last row last column cell has the ans for overall

       for(int i = 0; i<=n; i++){
           for(int j = 0; j<=w; j++) {
               if(i == 0 || j == 0) dp[i][j] = 0;
               // if curr chosen's wt > max wt available, then top cell's val is assigned
               else if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
               else {
               // find max btw top ele and val when curr element is chosen into sack
               dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);
               }
           }
           
       }
       return dp[n][w];
    }
};
