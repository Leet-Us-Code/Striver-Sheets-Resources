// Hari

class Solution {
public:
    // The Levenshtein Distance Problem [watch BacktoBack SWE's vid before]
    // Choose whether to delete, replace or insert a character based on whichever is 
    // the minimum cost operation. 
    
    // TC and SC - O(a*b) where a and b are lengths of the 2 words
    int minDistance(string word1, string word2) {
        int a = word1.size(), b = word2.size();
        
    // Create a 2D DP table with first element of both row and col as " " (empty string)
        // better use 2D vector instead of dp[a+1][b+1] when a and b (var) are used.
        // Easier to declare and initialize without errors
        vector<vector<int>> dp(a+1, vector<int> (b+1, 0));
        // Say word1 is hari (row) and word2 is haran (col)
        // First row of table contain the no. of steps from converting " " (row) into
        // " " (col) -> 0, into "h" -> 1, into "ha" -> 2, into "hara" -> 4, into "haran" -> 5
        // similarly for First column of table
        
        for(int i = 0; i<=a; i++) dp[i][0] = i;
        for(int j = 0; j<=b; j++) dp[0][j] = j;
        
        // now fill the remaining elements. 
        // If i and j letters don't match, take min(left, diag, top) + 1 as curr value
        // (Left -> Delete, Diagonal -> Replace, Top -> Insert) costs
        
        for(int i = 1; i<=a; i++){
            for(int j = 1; j<=b; j++){
                if(word1[i-1] != word2[j-1]) {
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]}); // use {} for calc min as > 2 elements are present
                } else {
                    // if words match, just add diagonal ele as curr..just like std 2D DP problems
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        // Bottom right will have the final # of operations...this is the bottoms up
        // approach as we solve smaller subproblems until our big bad ans is calculated!
        return dp[a][b];
        
        
    }
};
