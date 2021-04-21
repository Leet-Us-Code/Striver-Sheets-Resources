// Hari

class Solution {
public:
    // palindrome checking fun
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    //helper fun
    void part(int ind, string s, vector<string> &path, vector<vector<string>> &res ){
        if(ind == s.size()){
            //base case
            res.push_back(path);
            return;
        }
        for(int i = ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                // if substring from ind to i in s is a palindrome, push to path
                path.push_back(s.substr(ind, i-ind+1));
                part(i+1, s, path, res);
                // when coming back
                path.pop_back();
            }
        }
    }
    
    //driver main
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>path;
        part(0, s, path, res);
        return res;
    }
};
