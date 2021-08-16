class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n == 0)
        return 0;
        int b = (int)(log2(n));
        int x = pow(2,b);
        //for the numbers above x
        int part1 = b*pow(2,b-1);
        //for the numbers below x (including the MSB alone) recur for the remaining part
        int part2 = (n - x + 1);
        return part1+part2+countSetBits(n-x);
    }
};
