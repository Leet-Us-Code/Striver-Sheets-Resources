// Hari

int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxVal = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                count = 0;
            }
            else{
                count++;
                maxVal = max(maxVal, count);
            }
        }
        return maxVal;
    }
