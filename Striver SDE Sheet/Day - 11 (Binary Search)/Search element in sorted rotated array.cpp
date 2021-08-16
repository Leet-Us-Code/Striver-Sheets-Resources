// Hari

int search(vector<int>& nums, int target) {
        // rotated array will definitely have minimum ONE strictly inc. section
        int N = nums.size();
        int left = 0, right = N-1;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            // now we check if left part of mid strictly inc.
            else if(nums[mid] >= nums[left]){
                // check if target is in this strictly inc left part
                if(target >= nums[left] && target <= nums[mid]){
                    right = mid-1;
                } else {
                    //target not in strictly inc left part. So search right
                    left = mid+1;
                }
            }
            // if left part not strictly inc. 100% right part is strictly inc
            else {
                if(target >= nums[mid] && target <= nums[right]){
                    left = mid+1;
                }
                else right = mid-1;
            }
        }
        // if not found
        return -1;
    }
