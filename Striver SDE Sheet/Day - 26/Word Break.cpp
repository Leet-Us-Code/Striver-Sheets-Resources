// Hari
// Important Problem

class Solution {
public:
    /*
    dp[i] = true if a word ends at the i th pos. 
    Optimized soln is to look from current idx back until the pos with dp[pos] = true
    and then find the substring btw pos and current, and then check if this exists in wordDict
    
    If it does, then dp[curr] = true.
    
    Also, we use set to store words instead of vector we are given with, as set lookup O(logN)
    but vector is O(N). Set uses redblack trees to lookup faster
    
    */
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uSet(wordDict.begin(), wordDict.end());        
        int N = s.size();
        
        //for(auto it: wordDict) uSet.insert(it); -> also can be done
        
        
        vector<bool> dp(N+1, false);
        dp[0] = true; // empty string is a subset of all strings and can be formed with any wordDict
        
        for(int i = 1; i<=N; i++){
            for(int j = i-1; j>=0; j--){
                if(dp[j]){
                    // so we have found a j index with true val
                    // find substring
                    string newWord = s.substr(j, i-j);
                    if(uSet.find(newWord) != uSet.end()) {
                        // this word is found in set of words given. So mark the wordending index = True
                        dp[i] = true;
                        break; // go to next i
                    }
                }
            }
        }
        
        return dp[N];
    }
};

