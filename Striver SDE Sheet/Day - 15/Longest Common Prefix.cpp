// Hari

class Solution {
public:
    string helper(string s1, string s2){
        int t1 = 0, t2 = 0;
        while(t1 < s1.size() && t2 < s2.size()){
            if(s1[t1] == s2[t2]) {
                t1++;
                t2++;
            } else break;
        }
        return s1.substr(0, t1);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        // find the longest common prefix for first 2 strings in vector
        string res = helper(strs[0], strs[1]);
        // we get the LCP
        // check if this LCP exists within the rest of the strings in vector
        for(int i = 2; i<strs.size(); i++){
            res = helper(res, strs[i]);
        }
        return res;
    }
};

//Sid's solution
class Solution {
public:
    string helper(string s1, string s2)
    {
        int cntr = 0;
        string s;
        for(int i = 0; i < min(s1.length(), s2.length()); i++)
        {
            if(s1[i] != s2[i])
                break;
            cntr++;
        }
        return s1.substr(0, cntr);
    }
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size() == 1)
            return strs[0];
        res = helper(strs[0], strs[1]);
        for(int i = 2; i < strs.size(); i++)
        {
            res = helper(res, strs[i]);
        }
        return res;
    }
};
