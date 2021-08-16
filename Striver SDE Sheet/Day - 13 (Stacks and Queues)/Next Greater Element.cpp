// Hari

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for(int it: nums2){
            while(!s.empty() && it > s.top()){ // keep checking till it < top element
                m[s.top()] = it; // map element and its next greater ele
                s.pop();
            }
            s.push(it);
        }
        
        for(int &it: nums1){
            // if the element key exists (checked w count) then replace "it" with greater ele. Else -1
            it = m.count(it) ? m[it] : -1;
        }
        return nums1;
    }
