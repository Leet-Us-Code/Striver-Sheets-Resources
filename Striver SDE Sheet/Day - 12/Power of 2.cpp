  
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        int x = n-1;
        int res = (n&x);
        if(res == 0)
            return true;
        else
            return false;
    }
};
