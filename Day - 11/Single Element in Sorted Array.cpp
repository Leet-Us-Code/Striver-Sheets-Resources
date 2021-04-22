// Hari

int singleNonDuplicate(vector<int>& nums) {
        // Sorting, and hashing are 2 easy methods. This one is ad-hoc
        unordered_set<int> s;
        int sum1 = 0, sum2 = 0;
        for(int it: nums) s.insert(it);
        for(int i: s) sum1+=i;
        sum1 *= 2;
        for(int j: nums) sum2 += j;
        int res = sum1 - sum2;
        return res;
    }
