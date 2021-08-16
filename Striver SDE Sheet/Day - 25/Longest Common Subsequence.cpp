// Hari

int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        // create a 2D DP matrix with 1 extra row and col (filled w 0)
        int dp[s1 + 1][s2 + 1];
        //  or can do dp[][] = {0} also
        memset(dp, 0, sizeof dp);
        
        // iterate thru matrix in reverse (Bottom up approach)
        for(int i = s1-1; i>=0; i--){
            for(int j = s2-1; j>=0; j--){
                // if ele match, val will be 1 + val at diagonal
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1]; 
                }
                // if ele dont match, max of right and bottom val is assigned
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        // first row first col element will have the LCS value 
        int res = dp[0][0];
        return res;
        
    }
