// Sid

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        else if(x == 1)
            return 1;
        int l = 0 , r = x;
        int res = -1;
        while(l <= r)
        {
            int mid = (int)((l+r)/2);
            if(mid == x/mid)
            {
                return mid;
            }
            else if(mid < x/mid)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res;
    }
};
