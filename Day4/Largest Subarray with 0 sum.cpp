// Hari's

int maxLen(int A[], int n)
{
    unordered_map<int, int> m; // sum, index
    int sum = 0, maxLen = 0;
    
    for(int i = 0; i<n; i++){
        sum += A[i];
        if(A[i] == 0 && maxLen == 0) maxLen = 1;
        if(sum == 0) maxLen = i+1;
        // see if sum there in hashtable
        if(m.find(sum) != m.end()){
            maxLen = max(maxLen, i - m[sum]);
        }
        else {
            m[sum] = i;
        }
    }
    return maxLen;
}
