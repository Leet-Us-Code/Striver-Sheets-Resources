// Hari

bool checkInclusion(string s1, string s2) {
        // make 2 hashmaps for both strings
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        int N1 = s1.size();
        int N2 = s2.size();
        // we have to see if s2 contains permutation of s1
        if(N2 < N1) return false;
        
        
        // first we fill up hash counts in both
        int left = 0, right = 0;
        while(right < N1){
            hash1[s1[right] - 'a']++;
            hash2[s2[right] - 'a']++;
            right++;
        }
        right--; // point to end of first window
        
        while(right < N2){
            if(hash1 == hash2) return true;
            right++;
            if(right != N2){
                hash2[s2[right] - 'a']++;               
            }
            hash2[s2[left] - 'a']--;
            left++;
        }
        return false;
    }
