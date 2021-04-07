class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
        {
            vector<vector<int>> res;
            return res;
        }
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            
            int tar = 0 - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            while(r > l)
            {
                
                if(nums[r] + nums[l] == tar)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    output.push_back(temp);
                    temp.clear();
                    //removing duplicates here also 
                    while(r > l && nums[l] == nums[l+1])
                        l++;
                    while(r > l && nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] > tar)
                    r--;
                else 
                    l++;
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1])
                i++;
        }
        return output;
    }
};
