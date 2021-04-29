// Hari

void findCombi(int index, int target, vector<int>& arr, 
                   vector<vector<int>> &ans, vector<int> &ds){
        
        if(index == arr.size()) { // all candidates traversed - base case
            // after traversing all, target = 0. So eligible candidates are in ds now
            if(target == 0) ans.push_back(ds);
            return;
        }
        
        //pick up element
        if(arr[index] <= target){
            ds.push_back(arr[index]);
            findCombi(index, target-arr[index], arr, ans, ds); 
            // index same as MORE than once can be chosen
            // after reaching till end when coming back, remove this element from ds
            ds.pop_back();
            
        }
        
        // not picking element
        findCombi(index+1, target, arr, ans, ds);      
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // any qn like this, though process goes to Pick and Not Pick Recursion Method
        vector<vector<int>> ans;
        vector<int> ds; //holds current iteration chosen values
        findCombi(0, target, candidates, ans, ds);
        return ans;
    }

//Sid 

class Solution {
public:
    void helper(vector<int> candidates, int target, int i, int sum, set<vector<int>> &res, vector<int> r)
    {
        if(i == candidates.size())
            return;
        if(sum == target)
        {
            res.insert(r);
            return;
        }
        if(sum > target)
            return;
        helper(candidates, target, i+1, sum, res, r);
        r.push_back(candidates[i]);
        helper(candidates, target, i, sum+candidates[i], res, r);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> r;
        sort(candidates.begin(), candidates.end());
        vector<int> candidate;
        for(int i = 0; i < candidates.size(); i++)
        {
            while(i < candidates.size()-1 && candidates[i] == candidates[i+1])
                i++;
            candidate.push_back(candidates[i]);
        }
        helper(candidate, target, 0, 0, res, r);
        vector<vector<int>> result;
        for(auto it = res.begin(); it != res.end(); it++)
        {
            result.push_back(*it);
        }
        return result;
    }
};
