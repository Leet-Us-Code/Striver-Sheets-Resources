// Hari
// Iterative method

string countAndSay(int A) {
    if(A == 0) return "";
    if(A == 1) return "1";
    
    string ans = "1";
    string temp = "";
    
    while(A > 1){
        int N = ans.size();
        for(int i = 0; i<N; i++){
            int count  = 1;
            while(i+1 < N && ans[i] == ans[i+1]){
                count++;
                i++;
            }
            //temp = temp + to_string(count) + to_string(ans[i]); DONT DO THIS!
            temp.push_back((char)(count + '0')); // from int to char -> + '0' but char to int -> - '0'
            temp.push_back((char)(ans[i]));
        }
        ans = temp;
        temp = "";
        A--;
    }
    return ans;
}

//Sid 
//Recursive solution
class Solution {
public:
    string helper(int cur, string &s, int n)
    {
        if(cur > n)
            return s;
        else if(cur == 1)
        {
            s.push_back('1');
            return helper(cur+1, s, n);
        }
        else 
        {
            string s1;
            for(int i = 0; i < s.length(); i++)
            {
                int c = 1;
                while(i < s.length()-1 && s[i] == s[i+1])
                {
                    i++;
                    c++;
                }
                s1.push_back((char)(c+'0'));
                s1.push_back((char)(s[i]));
            }
            return helper(cur+1, s1, n);
        }
    }
    string countAndSay(int n) {
        string s;
        return helper(1, s, n);
    }
};
