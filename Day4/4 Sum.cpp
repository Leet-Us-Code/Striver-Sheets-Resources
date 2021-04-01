class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> set1;
        for(int i = 0; i < n-1; i++)
        {
            vector<int> temp;
            for(int j = i+1; j < n; j++)
            {
                int l = j+1;
                int r = n - 1;
                int sum = target - nums[i] - nums[j];
                while(l < r)
                {
                    if(nums[l] + nums[r] == sum)
                    {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        set1.insert(temp);
                        temp.clear();
                        l++;
                        r--;
                    }
                    else if(nums[l] + nums[r] > sum)
                        r--;
                    else
                        l++;
                }
            }
        }
        vector<vector<int>> res;
        for(auto it = set1.begin(); it != set1.end(); it++)
        {
            res.push_back(*it);
        }
        return res;
    }
};
