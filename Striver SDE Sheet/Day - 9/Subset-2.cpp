// Hari

void findAllSets(int ind, vector<int>& nums, vector<int> &ds, vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int i = ind; i<nums.size(); i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findAllSets(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds; // holds current list subset
        sort(nums.begin(), nums.end());
        findAllSets(0, nums, ds, ans);
        return ans;
    }
