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
