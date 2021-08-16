// Majority Element (>N/2 times)      
// One method is using Hashmap as usual. The most optimized method is MOORE'S VOTNG ALGORITHM

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore Voting algo
        int count = 0 , candidate = 0;
        
        for(int t: nums){
            if(count == 0) candidate = t;
            if(candidate == t) count++;
            else count--;
        }
        return candidate;
    }
};
