class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int l = 0;
        int r = 1;
        set<int> s;
        for(int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        
        vector<int> nums1;
        for(auto it = s.begin(); it != s.end(); it++)
        {
            nums1.push_back(*it);
        }
        int maxL = 1;
        while(l < nums1.size() && r < nums1.size())
        {
            if(nums1[r] - nums1[r-1] == 1)
            {
                r++;
            }
            else
            {
                maxL = max(maxL, r - l);
                l = r;
                r++;
            }
        }
        maxL = max(maxL, r - l);
        return maxL;
    }
};

// Hari's 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for(auto it: nums) hashSet.insert(it);
        
        int maxStreak = 0;
        for(int it: nums){
            if(!hashSet.count(it-1)){
                // if "it" is the smallest no. in a seq, start count from that "it"
                int currNum = it, currStreak = 1;
                
                while(hashSet.count(currNum+1)){
                    currNum = currNum+1;
                    currStreak += 1;
                    maxStreak = max(maxStreak, currStreak);
                }
                maxStreak = max(maxStreak, currStreak);
            }
        }
        return maxStreak;
    }
};
