// Hari

bool isAnagram(string s, string t) {
        int freq[26] = {0};
        for(int i = 0; i< s.size(); i++){
            freq[s[i] - 'a']++;
        }
        
        for(int i = 0; i<t.size(); i++){
            freq[t[i] - 'a']--;
        }
        
        // scan to see if any non zero element remains
        for(int z: freq){
            if(z != 0) return false;
        }
        return true;
    }
