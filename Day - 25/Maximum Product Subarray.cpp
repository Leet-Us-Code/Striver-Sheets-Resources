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
