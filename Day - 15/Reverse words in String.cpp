// Hari

string reverseWords(string s) {
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' ') continue;
            int l = i; // start of word
            while(i < s.size() && s[i] != ' ') i++; // move towards end of word
            // i is at end of word and l is the start of word
            if(ans.size() > 0) ans = " " + ans;
            string wordFormed = s.substr(l, i-l);
            ans = wordFormed + ans;
        }
        return ans; 
    }

//Sid 

class Solution {
public:
    string reverseWords(string s) {
        int i, j;
        i = 0, j = 0;
        while(i < s.length() && j < s.length())
        {
            if(s[i] == ' ')
            {
                while(i < s.length()-1 && s[i] == s[i+1]) 
                    i++;
                s[j] = s[i];
                j++;
                i++;
            }
            else
            {
                s[j] = s[i];
                j++;
                i++;
            }
        }
        s = s.substr(0,j);
        if(s[0] == ' ')
        {
            s = s.substr(1, s.length()-1);
        }
        if(s[s.length()-1] == ' ')
        {
            s = s.substr(0, s.length() - 1);
        }
        reverse(s.begin(), s.end());
        i = 0;
        j = 0;
        for(i = 0; i < s.length(); i++)
        {
            while(i < s.length() && s[i] != ' ')
            {
                i++;
            }
            int r = i - 1;
            i++;
            int l = j;
            while(l <= r)
            {
                swap(s[l], s[r]);
                l++;
                r--;
            }
            j = i;
        }
        return s;
    }
};


