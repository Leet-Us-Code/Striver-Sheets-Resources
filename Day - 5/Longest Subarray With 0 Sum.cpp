// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

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
