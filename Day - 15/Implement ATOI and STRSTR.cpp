// ATOI (Hari) Not satisfying stupid testcases on LC. Normal tc are fine

int myAtoi(string s) {
        int i = 0;
        int minVal = -2147483648;
        int maxVal = 2147483647;
        vector<int> finalNum;
        for(; i<s.size(); i++){
            if(s[i] == ' ') continue;
            else break;
        }
        s = s.substr(i, s.size()-i);
        // we may be at a sign, or number, or word
        int sign = 0;
        if(s[0] == '-'){
            sign = 1;
            s = s.substr(1,s.size()-1);
        }
        else if(s[0] == '+') s = s.substr(1,s.size()-1);
        int sum = 0;
        i = 0;
        while(i < s.size() && isdigit(s[i])){
            finalNum.emplace_back(s[i] - '0');
            i++;
        }
        int N = finalNum.size();
        long long int finalAns = 0;
        for(int j = 0; j<N; j++){
            if(finalAns > 9223372036854775807) break;
            long long int temp = finalNum[j]*pow(10,N - j - 1);
            finalAns += temp;
        }
        if(sign){
            finalAns = -finalAns;
        }
        if(finalAns < minVal) return minVal;
        if(finalAns > maxVal) return maxVal;
        return finalAns;
    }

// not my soln

class Solution {
public:
    int myAtoi(string str) {
    if (str.empty()) return 0;
    int i = 0, sign = 1;
    while (i + 1 < str.size() && isspace(str[i])) ++i;
    long res = 0;
    if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
    while (i < str.size()) {
        if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
        else return res * sign;
        if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
    }
    return res * sign;
}
};

// STRSTR (Sid)
