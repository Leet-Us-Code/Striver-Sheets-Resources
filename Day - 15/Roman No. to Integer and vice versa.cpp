// Hari

// Roman no. to integer

int romanToInt(string A) {
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0, i = 0, N = A.size();
        while(i < N){
            if(m[A[i]]< m[A[i+1]]) ans-=m[A[i]];
            else ans+=m[A[i]];
            i++;
        }
        //ans+=m[A[i]];
        return ans;
    }
  
 // Integer to Roman no.

string intToRoman(int A) {
        string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", 
             "V", "IV", "I"}; 
        // I can only be placed before V and X.
        // X can only be placed before L and C.
        // C can only be placed before D and M.
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        if(A<1 || A>3999) return "";

        int i = 0;
        string res = "";
        while(A > 0)
        {
            if(A - values[i] >= 0)
            {
                res += numerals[i];
                A = A - values[i];
            }
            else
            {
                i++;
            }
        }


        return res;
        }
