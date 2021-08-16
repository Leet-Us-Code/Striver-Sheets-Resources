// Decently optimized method is using standard DP to store no of ways of entring that particular coordinate, and using it instead of calculating again next time. 
// This one is based on the basic no. of combinations needed to reach END from START -> Combinatorics Method -> O(m-1) or O(n-1), O(1)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2; // (m-1)+(n-1) is the total no. of indexes of combinations 
        // ie. n in nCr
        int r = m-1; // can be n-1 also
        //now we find nCr
        double ans = 1;
        for(int i = 1; i<=r; i++){
            ans = ans * (N-r+i)/i;
        }
        return (int) ans;
    }
};



