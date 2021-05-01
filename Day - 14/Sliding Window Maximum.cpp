// Hari

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; 
        vector<int> ans;
        
        for(int curr = 0; curr<nums.size(); curr++){
            // outdated element nums[curr-k] is removed
            if(dq.front() == curr - k) dq.pop_front();
            // if curr element > dq's top, keep pop-ing it. All elements in dq < nums[curr] are removed as they have o chance of getting selected in window range
            while(!dq.empty() && nums[dq.back()] < nums[curr]) dq.pop_back();
            // now we add the nums[curr] to dq
            dq.push_back(curr);
            // the front of dq has the largest number in (curr-k, curr) window
            if(curr - k + 1 >= 0) ans.emplace_back(nums[dq.front()]);
        }
        return ans;
    }
