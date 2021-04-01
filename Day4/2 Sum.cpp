class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> x;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            x.push_back(make_pair(nums[i], i));
        }
        sort(x.begin(), x.end());
        int l = 0;
        int r = n-1;
        vector<int> res;
        while(l < r)
        {
            if(x[l].first + x[r].first == target)
            {
                res.push_back(x[l].second);
                res.push_back(x[r].second);
                break;
            }
            else if(x[l].first + x[r].first > target)
                r--;
            else
                l++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
