// Fast Exponential algorithm

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; 
        if(nn < 0) nn = -1 * nn;
        
        while(nn){ // till its not 0
            if(nn%2 == 0){ // even power
                x = x * x;
                nn /= 2;
            }
            else { // odd power
                ans = ans * x;
                nn -= 1;
            }
        }
        if(n < 0) ans = (double)1.0 / (double) ans;
        return ans;
    }
};
