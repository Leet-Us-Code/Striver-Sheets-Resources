// Hari

int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];
        
        // use do while to run first time even when fast = slow. while will simply break @ start
        // and do while will run any code min 1 time irrespective of condition
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);
        
        // fast will stay at meeting point and slow comes back to start
        slow = nums[0];
        
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow; // return fast;
    }
