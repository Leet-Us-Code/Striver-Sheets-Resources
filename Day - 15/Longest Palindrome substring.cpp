// Sid 
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

// Hari

string longestPalindrome(string s) {
        int N = s.size();
        int maxLen = 1; // as a single letter is also a palindrome
        int start = 0; // assigning the start of the longest palindrome
        
        for(int i = 0; i<N; i++){
            // check for odd size palindrome from this index
            int l = i - 1;
            int r = i + 1;
            while(l >= 0 && r < N && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l-- ; r++;
            }
            
            // check for even size palindrome from this index
            l = i;
            r = i + 1;
            while(l >= 0 && r < N && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l-- ; r++;
            }
        }
        
        return s.substr(start, maxLen);
    }
