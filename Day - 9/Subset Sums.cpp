// Hari

void helper(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset){
        if(ind == N){
            sumSubset.push_back(sum); //basecase. When pointer reaches end, push sum into vector
            return;
        }
        
        // pick element
        helper(ind+1, sum+arr[ind], arr, N, sumSubset);
        
        // not picking element
        helper(ind+1, sum, arr, N, sumSubset);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumSubset;
        helper(0,0,arr,N,sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
