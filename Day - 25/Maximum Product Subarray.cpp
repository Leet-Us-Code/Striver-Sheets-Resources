// Hari

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
