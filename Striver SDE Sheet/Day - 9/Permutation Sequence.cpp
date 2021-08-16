// Hari

string getPermutation(int n, int k) {
        // kth permutation (lexicographically) in n!
        int fact = 1;
        vector<int> nums;
        for(int i = 1; i<n; i++){
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n); // we want fact to be (n-1)! as ifyou fix an element's pos then n-1 pos are free. 
        string res = "";
        k -= 1; // as n is 1-indexed
        while(true){
            res = res + to_string(nums[k / fact]);
            // now remove this chosen num from nums
            nums.erase(nums.begin()+(k/fact));
            if(nums.size() == 0){
                //base case
                break;
            }
            k = k % fact;
            fact = fact / nums.size();
        }
        
        return (string)res;
    }
