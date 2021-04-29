  
int setBitNumber(int n)
{
 
    // To find the position
    // of the most significant
    // set bit
    int k = (int)(log2(n));
 
    // To return the the value
    // of the number with set
    // bit at k-th position
    return 1 << k;
}
