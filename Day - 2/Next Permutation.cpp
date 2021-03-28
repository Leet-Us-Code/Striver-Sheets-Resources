class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                ind = i-1;
                break;
            }
        }
        if(ind == -1)
            sort(nums.begin(), nums.end());
        else 
        {
            int min1 = INT_MAX;
            int minInd = -1;
            for(int i = ind+1; i < nums.size(); i++)
            {
                if(nums[i] > nums[ind])
                {
                    if(min1 > nums[i])
                    {
                        min1 = nums[i];
                        minInd = i;
                    }
                }
            }
            swap(nums[ind], nums[minInd]);
            vector<int> ::iterator it1 = nums.begin();
            advance(it1, ind+1);
            sort(it1, nums.end());
        }
    }
};
