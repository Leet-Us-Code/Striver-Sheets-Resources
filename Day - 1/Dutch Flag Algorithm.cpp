class Solution
{
public:
    void sortColors(vector<int> &A)
    {
        int low = 0, mid = 0;
        int hi = A.size() - 1;

        while (mid <= hi)
        {
            if (A[mid] == 0)
                swap(A[mid++], A[low++]);
            else if (A[mid] == 1)
                mid++;
            else
            {
                // if it is 2
                swap(A[mid], A[hi--]); // no increment of mid. Only hi decrement
            }
        }
    }
};