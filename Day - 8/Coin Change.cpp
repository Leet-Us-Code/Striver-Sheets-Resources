// Hari

int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        sort(coins.begin(), coins.end(), greater<int>());
        dp[0] = 0; // no. of coins for amount = 0 is 0
        for(int i = 1; i<=amount; i++) dp[i] = INT_MAX;
        
        int N = coins.size();
        
        for(int i = 1; i<= amount; i++){
            for(int j = 0; j<N; j++){
                if(coins[j] <= i){ // if this coin can be picked
                    int rem = dp[i-coins[j]];
                    if(rem !=INT_MAX && rem+1 < dp[i]) dp[i] = rem+1;
                }
            }
        }
        
        return dp[amount] == INT_MAX? -1: dp[amount];
    }
