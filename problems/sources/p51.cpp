int main()
{
    int n = 3234, sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}