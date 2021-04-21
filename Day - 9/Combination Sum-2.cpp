// Hari

void findCombi(int ind, int target, vector<int> &candidates, 
                  vector<vector<int>> &ans, vector<int> &ds){
        
        if(target == 0){ // base case. We found a valid combination
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind; i<candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue; // to avoid
            //adding same element to ds ie. forming 2 ds of same elements
            if(candidates[i] > target) break; // no need to pursue as all candidates
            //after current will also be > target. 
            
            // if all condt pass and element is valid
            ds.push_back(candidates[i]);
            //next call
            findCombi(i+1, target-candidates[i], candidates, ans, ds);
            // on return from this call, remove added candidates[i] so that we can try diff branch of recursion tree without curr element in it
            ds.pop_back();
        }
    }

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds; // datastructure to hold current interation elements
        findCombi(0, target, candidates, ans, ds);
        return ans;
    }
