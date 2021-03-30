// Majority Element when > N/3. In prev qn, as it was N/2 the max no. of distinct elements w floor(N/2) occurence is 1 [0-1]
// Here, max no can be 2 elements [0-2]

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int N = nums.size();
        int count1 = 0, count2 = 0, candidate1 = -1, candidate2 = -1;
        
        for(int i = 0; i<N; i++){
            if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
            
            else if(count1 == 0){
                count1 = 1;
                candidate1 = nums[i];
            }
            else if(count2 == 0){
                count2 = 1;
                candidate2 = nums[i];
            }
            else{
                count1--;
                count2--;
            }
        }
        
        // traverse to see if these elements are actually major ele
        vector<int> ans;
        int c1 = 0, c2 = 0;
        for(int i = 0; i<N; i++){
            if(nums[i] == candidate1) c1++;
            else if(nums[i] == candidate2) c2++;
        }
        if(c1 > N/3) ans.push_back(candidate1);
        if(c2 > N/3) ans.push_back(candidate2);
        
        return ans;
    }
};
