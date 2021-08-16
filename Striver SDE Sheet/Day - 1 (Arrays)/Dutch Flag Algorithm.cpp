// Hari
// https://leetcode.com/problems/sort-colors/

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
                swap(A[mid], A[hi--]); // no increment of mid. Only hi decrement as we have included mid condt in 0 and 1 case, and sometimes we get a 0 after swapping
                // with hi which might not get swapped with low if we incremented mid here also.
            }
        }
    }
};
