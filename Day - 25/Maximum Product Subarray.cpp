// Hari

// Method - 1
int maxProduct(vector<int>& nums) {
        int minProd = 1;
        int maxProd = 1;
        int result = INT_MIN;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < 0) swap(minProd, maxProd); // when no. -ve

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            
            result = max(result, maxProd);
        }
        return result;
    }

// Method - 2

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // we need 2 variables max_ending_here and min_ending_here (for -ve numbers)
        int N = nums.size();
        int max_ending_here = nums[0];
        int min_ending_here = nums[0];
        int maxOverall = nums[0]; // return this
        
        for(int i = 1; i<N; i++){
            int temp_max_ending_here = max_ending_here;
            // 2 methods of finding max or min. 
            // Method - 1
            // max_ending_here = max(nums[i], max(max_ending_here * nums[i], 
            //                                           min_ending_here * nums[i]));
            
            // Method - 2 (when > 2 elements to find max, just put everything in {})
            max_ending_here = max({nums[i], max_ending_here * nums[i], 
                                                      min_ending_here * nums[i]});
            min_ending_here = min(nums[i], min(temp_max_ending_here * nums[i], 
                                                      min_ending_here * nums[i]));
            maxOverall = max(maxOverall, max_ending_here);
        }
        return maxOverall;
        
    }
};


// Sid 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int temp = maxProd;
            maxProd = max(nums[i], max(nums[i]*maxProd, nums[i]*minProd));
            minProd = min(nums[i], min(temp*nums[i], minProd*nums[i]));
            res = max(res, maxProd);
        }
        
        return res;
        
    }
};
