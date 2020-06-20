int count01(int n)
{
    int mask1 = 1, mask2 = 2;
    int count = 0;
    while(n != 0) {
        if((mask1 & n) && !(mask2 & n)) count++;
        n >> 1;
    }
    return count;
}
