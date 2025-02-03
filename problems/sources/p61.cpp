int main()
{
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int gcd = nums[0];

    for (int i = 1; i < 10; ++i)
    {
        int a = gcd, b = nums[i];
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        gcd = a;
    }
    return gcd;
}