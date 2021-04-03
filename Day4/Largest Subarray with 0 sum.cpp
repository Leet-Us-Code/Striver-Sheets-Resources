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


//Sid's solution
int maxLen(int a[], int n)
{
    int sum[n+1];
    sum[0] = 0;
    for(int i = 1; i < n+1; i++)
    {
        sum[i] = sum[i-1] + a[i-1];
    }
    map<int, int> m;
    int length = 0;
    for(int i = 0; i < n+1; i++)
    {
        if(m[sum[i]] == 0)
        {
            m[sum[i]] = i+1;
        }
        else 
        {
            length = max(length, i + 1 - m[sum[i]]);
        }
    }
    return length;
}
