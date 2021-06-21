// Hari

// There is a better O(NLogN) answer. Try to understand that in Phase-2 prep

int lengthOfLIS(vector<int>& nums) {
        // start from last element and check if its next ele can be included in subseq
        // iff curr ele < next elements 
        
        // O(N^2) as we check for an element, all the elements after it
        int N = nums.size();
        int res = 1;
        
        // all LIS should be min 1 (with self)
        vector<int> LIS(N, 1);
        for(int i = N-2; i>=0; i--){
            for(int j = i+1; j<N; j++){
                if(nums[i] < nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                    res = max(res, LIS[i]);
                }
            }
        }
        return res;
    }
