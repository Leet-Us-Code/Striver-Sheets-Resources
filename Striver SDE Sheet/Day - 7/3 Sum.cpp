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
            //remove duplicates here for the case [x,x,x,-1,-1,-1]..if you put this loop in the starting it will just quit the loop without considering any of the -1's
            while(i < nums.size() - 1 && nums[i] == nums[i+1])
                i++;
        }
        return output;
    }
};


// Hari's
// Do not use sets as insertions is O(logN) and we have to move it to 2-D vec also

vector<vector<int>> threeSum(vector<int>& nums) {
        //set<vector<int>> s;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int l, r;
        
        for(int i = 0; i<nums.size(); i++){
            l = i+1;
            r = nums.size()-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) r--;
                else if(sum < 0) l++;
                else {
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[l]);
                    ans.push_back(nums[r]);
                    //s.insert(ans);
                    res.push_back(ans);
                    ans.clear();
                    //removing duplicates here also 
                    while(r > l && nums[l] == nums[l+1])
                        l++;
                    while(r > l && nums[r] == nums[r-1])
                        r--;
                    
                    l++; r--;
                }
            }
            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
        // for(auto it: s){
        //     res.push_back(it);
        // }
        return res;
    }
