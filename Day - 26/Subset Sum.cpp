// Hari

int Solution::solve(vector<int> &A, int B) {
    int N = A.size(); 
    // create a DP table with N+1 rows and B+1 columns
    bool dp[N+1][B+1];
    
    // First col will be fully true(1)->U can make sum=0 with any element from A ie.
    // empty set gives sum 0. 
    // First row(barring first element) will be false as u cant make sum=column elements
    // with no elements in vector A.
    
    for(int j = 0; j<=B; j++) dp[0][j] = false;
    for(int i = 0; i<=N; i++) dp[i][0] = true;
    
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=B; j++){
            if(A[i-1] > j) dp[i][j] = dp[i-1][j]; // if ele of A chosen > curr sum ele of B
            else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
                // OR gives max btw both bools. First term is when ele of A not chosen.
                // Second is if its chosen, subtract that val from sum and see state of 
                //resultant element value
            }
        }
    }
    
    return (int)dp[N][B]; //bottom rightmost element gives final ans (0->F 1->T)
    
}
