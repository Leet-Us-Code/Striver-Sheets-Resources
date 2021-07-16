// Hari

class Solution {
public:
    int climbStairs(int n) {
       // DP Method
       vector<int> dp(n+1, 0);
       if(n == 0 || n == 1 || n == 2) return n;

       dp[0] = 1; // only way to walk 0 stairs is to not walk (1)
       dp[1] = 1; 

       for(int i = 2; i<=n; i++){
           dp[i] = dp[i-1] + dp[i-2];
       }
       return dp[n];
        
        
        // Fibonacci method - almost the exact same as DP
        if(n == 0 || n == 1 || n == 2) return n; // base
        int finalWays = 0;
        int oneStepBef = 2;
        int twoStepsBef = 1;
        
        for(int i = 2; i<n; i++){
            finalWays = oneStepBef + twoStepsBef;
            twoStepsBef = oneStepBef;
            oneStepBef = finalWays;
        }
        
        return finalWays;
    }
};
