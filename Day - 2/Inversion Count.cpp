class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long int a[], long long int l, long long int mid, long long int r)
    {
        long long int n1, n2;
        n1 = mid - l + 1;
        n2 = r - mid;
        long long left[n1], right[n2];
        for(int i = 0; i < n1; i++)
        {
            left[i] = a[l+i];
        }
        for(int i = 0; i < n2; i++)
        {
            right[i] = a[mid+1+i];
        }
        long long int i = 0, j = 0;
        long long int count = 0;
        long long int k = l;
        while(i < n1 && j < n2)
        {
            if(left[i] > right[j])
            {
                a[k] = right[j];
                count = count + (n1-i);
                j++;
                k++;
            }
            else
            {
                a[k] = left[i];
                i++;
                k++;
            }
        }
        while(i < n1 )
        {
            a[k] = left[i];
            i++;
            k++;
        }
        while(j < n2)
        {
            a[k] = right[j];
            j++;
            k++;
        }
        return count;
        
    }
    long long int inversions(long long int a[], long long int l, long long int r)
    {
        long long int count = 0;
        if(r > l)
        {
            long long int mid = l + (r-l)/2;
            count += inversions(a, l, mid);
            count += inversions(a, mid+1, r);
            count += merge(a, l, mid, r);
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return inversions(arr, 0, N-1);
    }

};
