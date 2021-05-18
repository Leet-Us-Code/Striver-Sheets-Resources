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
