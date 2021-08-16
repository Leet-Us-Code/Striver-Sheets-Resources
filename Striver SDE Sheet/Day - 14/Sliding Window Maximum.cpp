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


//Sid's solution

  
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //first find the next greater element 
        //in a window if  the next greater element of an element is outside the window then tha will be the maximum element in the window. If the next greater element
        //exists in the window then go to the next greater element and check it again, then mark it the greatest.
        int nge[100000];
        stack<int> s;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(s.empty())
            {
                s.push(i);
            }
            else 
            {
                if(nums[i] > nums[s.top()])
                {
                    while(!s.empty() && nums[i] > nums[s.top()])
                    {
                        nge[s.top()] = i;
                        s.pop();
                    }
                    s.push(i);
                }
                else
                {
                    s.push(i);
                }
            }
        }
        while(!s.empty())
        {
            nge[s.top()] = n;
            s.pop();
        }
        vector<int> res;
        int j = 0;
        for(int i = 0; i <= n-k; i++)
        {
            if(j < i)
            {
                j = i;
            }
            while(nge[j] < i+k)
            {
                j = nge[j];
            }
            res.push_back(nums[j]);
        }
        return res;
    }
};
