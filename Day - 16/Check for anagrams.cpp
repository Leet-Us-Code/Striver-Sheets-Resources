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

//Sid's solution

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq1[128] = {0};
        int freq2[128] = {0};
        for(int i = 0; i < s.length(); i++)
        {
            freq1[s[i]]++;
        }
        for(int i = 0; i < t.length(); i++)
        {
            freq2[t[i]]++;
        }
        for(int i = 0; i < 128; i++)
        {
            if(freq1[i] != freq2[i])
                return false;
        }
        return true;
    }
};
