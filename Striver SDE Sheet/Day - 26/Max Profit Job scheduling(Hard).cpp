// Hari

class Solution {
public:
    
    int helper(int idx, vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &dp){
        int N = A.size();
        if(idx == N-1) return C[idx];
        if(dp[idx] != -1) return dp[idx];
        // next possible starttime job after idx th job which ends at B[idx] time
        auto curr = lower_bound(A.begin()+idx, A.end(), B[idx]); 
        
        int chosen, notchosen; // profit when curr job is chosen and not chosen
        
        // when the job is chosen
        if(curr == A.end()) chosen = C[idx]; // if last job left just assign its profit
        else {
            chosen = C[idx] + helper(curr-A.begin(), A, B, C, dp); // curr job profit + max profit from next jobs available after curr
        }
        
        // when the job is skipped
        notchosen = helper(idx+1, A, B, C, dp);
        
        return dp[idx] = max(chosen, notchosen); // added max profit to dp table
    }
    
    
    static bool comp(vector<int> &A, vector<int> &B){
        if(A[0] == B[0]){
            if(A[1] == B[1]) return A[2] > B[2]; // desc order of profit
            return A[1] < B[1]; // asc order of endTime
        }
        return A[0] < B[0]; // asc order of startTime
    }

    
     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = startTime.size();
        vector<vector<int>> AA; // this will help us form startT, endT, profit sorted in right way
        for(int i = 0; i<N; i++){
            AA.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(AA.begin(), AA.end(), comp); 
        startTime.clear();
        endTime.clear();
        profit.clear();
        
        for(auto &it: AA){
            startTime.push_back(it[0]);
            endTime.push_back(it[1]);
            profit.push_back(it[2]);
        }
        
        // dp vector
        // we will traverse jobs left to right 
        vector<int> dp(N, -1);
        return helper(0, startTime, endTime, profit, dp);
    }

};
