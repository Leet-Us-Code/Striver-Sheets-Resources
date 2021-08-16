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


//Sid 
//Integer to Roman 
class Solution {
public:
    string intToRoman(int num) {
        string s;
        vector<pair<string, int>> mp;
        mp.push_back({"I", 1});
        mp.push_back({"IV", 4});
        mp.push_back({"V", 5});
        mp.push_back({"IX",9});
        mp.push_back({"X", 10});
        mp.push_back({"XL",40});
        mp.push_back({"L", 50});
        mp.push_back({"XC", 90});
        mp.push_back({"C", 100});
        mp.push_back({"CD", 400});
        mp.push_back({"D", 500});
        mp.push_back({"CM",900});
        mp.push_back({"M", 1000});
        while(num > 0)
        {
            int x;
            for(int i = 0; i < mp.size(); i++)
            {
                if(mp[i].second <= num)
                {
                    x = i;
                }
            }
            s += mp[x].first;
            num = num - mp[x].second;
            
        }
        return s;
    }
};

//roman to integer
class Solution {
public:
    int romanToInt(string s) {
        vector<int> x;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'I')
            {
                x.push_back(1);
            }
            else if(s[i] == 'V')
            {
                x.push_back(5);
            }
            else if(s[i] == 'X')
            {
                x.push_back(10);
            }
            else if(s[i] == 'L')
            {
                x.push_back(50);
            }
            else if(s[i] == 'C')
            {
                x.push_back(100);
            }
            else if(s[i] == 'D')
            {
                x.push_back(500);
            }
            else if(s[i] == 'M')
            {
                x.push_back(1000);
            }
        }
        int num = 0;
        int n = x.size();
        int c = n-1;
        while(c >= 0)
        {
            if(c > 0 && x[c] > x[c-1])
            {
                num += (x[c] - x[c-1]);
                c = c - 2;
            }
            else 
            {
                num += x[c];
                c--;
            }
        }
        return num;
    }
};
