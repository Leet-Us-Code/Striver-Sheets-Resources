// Hari

class Solution{
public:
    int helper(int i, int j, int arr[], vector<vector<int>> &dp)
    {
        if(i == j) return 0; // in A(CD) A is a singular ele so 0 is cost of multiplying
        int minCost = INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j]; // memoization
        
        for(int k = i; k<j; k++){
            // all the various places to divide
            int count = helper(i, k, arr, dp) + helper(k+1, j, arr, dp) + arr[i-1] * arr[k] * arr[j];
            // in A(BCD) we find cost of A(0) + cost(BCD) + cost of multiplying A*B*C*D
            if(count < minCost) {
                minCost = count;
                dp[i][j] = count; // we add this new cost in lookup dp table
            }
            
        }
        
        return minCost;
    }



    int matrixMultiplication(int N, int arr[])
    {
        // we will be using memoization using DP to store already calculated costs
        vector<vector<int>> dp(N, vector<int> (N, -1)); 
        // we can divide in N-1 places starting from 1
        // A(BCD) , AB(CD), ABC(D) where first ( is at 1,2,3 places resp. )
        return helper(1, N-1, arr, dp);
    }
};
