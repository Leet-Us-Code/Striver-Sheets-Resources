//Sid 
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
        int n = s.length();
        string res;
        int startInd = 0;
        //for each index, check if even or odd length palindrome can be formed from that character given the character is the pivot of the palindrome
        for(int i = 0; i < n; i++)
        {
            //odd palindrome 
            int l = i - 1;
            int r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                if(r - l + 1 > maxLen)
                {
                    maxLen = r - l + 1;
                    startInd = l;
                }
                l--;
                r++;
            }
            //even palindrome 
            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r])
            {
                if(r - l + 1 > maxLen)
                {
                    maxLen = r - l + 1;
                    startInd = l;
                }
                l--;
                r++;
            }
            
        }
        return s.substr(startInd, maxLen);
    }
};
