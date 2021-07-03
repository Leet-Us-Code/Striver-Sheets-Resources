// Hari
/*
 Refer: https://bit.ly/3hbmWuT
 Method - 1 -> "Naive" using 2-D (n*k) matrix 
 Useful for grasping the concept
 
*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        // k -> no of eggs and n -> no of floors in building
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));  // n x k matrix 
        
        /*
    EXPLANATION (n -> floors, e -> eggs count)
    1) F[n][e] = min(max(F[n-x][e], F[x-1][e-1]) + 1)
                x = 1->n-1
    Minimize the max (worst case) to get least no. of tries to get the right floor.

    F[n-x][e] is when egg doesn't break. e remains same and we need to focus on higher
    floors (n-x)

    F[x-1][e-1] is when egg does break. e-1 eggs left. So to find breaking point floor, 
    we go down (x-1).

    The +1 at the end is for counting the one try (dropping egg) from current floor, 
    irrespective of whether egg is broken or not

    2) 2 constraints: F[1][e] = 1 as if we have 1 floor left and any no. of eggs,
    only 1 try is possible anyways. F[n][1] = n as if we have n floors to check and 1 egg
    left, we start from bottom floor and keep dropping same egg in each higher floor till 
    it breaks. (worst case n floors)       
        */
        
        for(int i = 0; i<n+1; i++) dp[i][1] = i; // first column (2nd constraint from above)
        for(int j = 0; j<k+1; j++) dp[1][j] = 1; // first row (1st constraint from above)
        
        for(int i = 2; i<n+1; i++) {
            for(int j = 2; j<k+1; j++) {
                dp[i][j] = INT_MAX;
                // for x in 1 to n-1
                for(int x = 1; x<i; x++){
                    int brokenEgg = dp[x-1][k-1];
                    int unbrokenEgg = dp[i-x][k];
                    int temp = max(brokenEgg, unbrokenEgg) + 1;
                    if(temp < dp[i][j]) dp[i][j] = temp;
                }
                
            }
        }
        
        return dp[n][k]; // bottom up approach. 
    }
};


// Method - 2


