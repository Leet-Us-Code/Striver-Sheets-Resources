//Sid's
int findPlatform(int arr[], int dep[], int n)
{
    int i = 0, j = 0, plat = 0;
    sort(arr,arr+n);
    sort(dep,dep+n);
    int maxP = INT_MIN;
    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            plat++;
            i++;
        }
        else 
        {
            plat--;
            j++;
        }
        maxP = max(maxP, plat);
    }
    return maxP;
}
