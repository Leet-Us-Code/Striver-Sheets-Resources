class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size(), ind = -1;
        for(int i = N-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                ind = i-1;
                break;
            }
        }
        
        if(ind == -1) reverse(nums.begin(), nums.end());
        else {
            // check smallest no > nums[ind]
            int minIdx;
            for(int i = N-1; i>ind; i--){
                if(nums[i] > nums[ind]){
                    minIdx = i;
                    break;
                }
            }
            
            swap(nums[minIdx], nums[ind]);
            
            reverse(nums.begin() + ind + 1, nums.end());
        }
    }
};
