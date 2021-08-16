// Hari

// Method1 - amount is the outer loop

int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        // make dp table (1D) for each amount from 0->amount. 
        // Each will tell min coins needed to attain that particular cell's amount(j)
        // Bottom up approach
        
        vector<int> dp(amount+1, 69696969);
        dp[0] = 0; // for 0 amount, 0 coins needed 
        
        for(int i = 1; i<=amount; i++){
            for(int j = 0; j<coins.size(); j++){
                if(coins[j] <= i){
                    // this coin can be counted to this amount
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                } else continue;
            }
        }
        
        return dp[amount] == 69696969? -1 : dp[amount]; // 69696969 is an arbitrary arge no.

    }

// Method2 - coins is the outer loop. Saves some time by removing the if condition 

int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 69696969);
        dp[0] = 0; // For 0 amount, 0 coins needed
        
        for(int i = 0; i<coins.size(); i++){ // traversing coins array
            for(int j = coins[i]; j<=amount; j++){ // amount is always >= current coin chosen
                // so no need if condt to check if coin chosen < j(amount)
                dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            }
        }
        
        return dp[amount] == 69696969? -1 : dp[amount];
    }
