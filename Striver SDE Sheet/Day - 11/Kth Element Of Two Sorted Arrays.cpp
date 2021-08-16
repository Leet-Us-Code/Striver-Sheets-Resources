//Sid
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int p1 = 0, p2 = 0;
        int cntr = 0;
        while(p1 < n && p2 < m)
        {
            if(arr1[p1] < arr2[p2])
            {
                cntr++;
                if(cntr == k)
                {
                    return arr1[p1];
                }
                p1++;
            }
            else 
            {
                cntr++;
                if(cntr == k)
                {
                    return arr2[p2];
                }
                p2++;
            }
        }
        while(p1 < n)
        {
            cntr++;
            if(cntr == k)
            return arr1[p1];
            p1++;
        }
        while(p2 < m)
        {
            cntr++;
            if(cntr == k)
            return arr2[p2];
            p2++;
        }
    }
};
