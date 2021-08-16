class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int x = pow(2,n);
        vector<vector<int>> res;
        for(int i = 0; i < x; i++)
        {
            vector<int> temp;
            for(int j = 0; j < n; j++)
            {
                if(i&(1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
