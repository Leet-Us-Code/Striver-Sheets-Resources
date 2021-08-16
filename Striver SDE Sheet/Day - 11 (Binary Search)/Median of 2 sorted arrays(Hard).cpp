// Hari

class Solution {
public:
    // helpers
    int getMax(vector<int> nums, int part){
        if(part == 0){
            // if partition is in front of nums then leftX should be INT_MIN and not some random garbage value
            return INT_MIN;
        }
        else return nums[part-1];
    }
    
    int getMin(vector<int> nums, int part){
        // if partition goes out of bounds of nums
        if(part == nums.size()){
            return INT_MAX;
        }
        else return nums[part];
    }

    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // HARD COMMON INTERVIEW DnC QN
        // nums1 has to be the smaller of the two
        if(nums1.size() > nums2.size()){
            nums1.swap(nums2);
        }
        
        int low = 0, hi = nums1.size();
        int combinedLength = nums1.size() + nums2.size();
        // combinedL can either be even or odd. Flow goes based on which one it is
        
        while(low <= hi){
            int partX = low + (hi-low) / 2; // partition in nums1
            int partY = (combinedLength + 1) / 2 - (partX);
            
            // get no. directly to left of partitions (both)
            int leftX = getMax(nums1, partX);
            int leftY = getMax(nums2, partY);
            
            // get no. directly to right of partitions (both)
            int rightX = getMin(nums1, partX);
            int rightY = getMin(nums2, partY);
            
            /* 2 conditions for both arr partitions to be valid
            1. no. on left of partX (nums1) <= no. on right of partY (nums2)
            2. no. on left of partY (nums2) <= no. on right of partX (nums1)
            */
            
            // partitions valid check
            if(leftX <= rightY && leftY <= rightX){
                double res;
                if(combinedLength % 2 == 0){
                    // even -> max of left partitions + min of right / 2
                    res = (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
                    //used 2.0 for double dtype division  
                }
                else {
                    res = max(leftX, leftY); // odd->max of left sides of both partitions will give median of combined array 
                }
                return res;
            }
            
            // if current partitions invalid 
            if(leftX > rightY) hi = partX - 1;
            else if(leftY > rightX) low = partX + 1;  
        }
        
        return -1;
        
        
    }
    
};
