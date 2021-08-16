int *findTwoElement(int *arr, int n)
{
    // code here
    int xor1 = 0;
    for (int i = 0; i < n; i++)
        xor1 = xor1 ^ arr[i];
    for (int i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
    //{1,3,3} and {1,2,3}
    //2^3 => 5
    //repeating -> first arrayb
    //missing array -> second array
    //x & ~(x-1)
    int setBit = xor1 & (~(xor1 - 1));
    int x = 0, y = 0;
    //first array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & setBit)
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }
    //second array
    for (int i = 1; i <= n; i++)
    {
        if (i & setBit)
        {
            x = x ^ i;
        }
        else
        {
            y = y ^ i;
        }
    }
    int *res;
    //we ll search for x or y in the first array
    int flagx = 0;
    int flagy = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            flagx = 1;
            break;
        }
        else if (arr[i] == y)
        {
            flagy = 1;
            break;
        }
    }
    if (flagx == 1)
    {
        res[0] = x;
        res[1] = y;
        return res;
    }
    else
    {
        res[0] = y;
        res[1] = x;
        return res;
    }
}
