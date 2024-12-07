
int main()
{
    int n = 67;
    for (int i = 0; i < n / 2; i++)
    {
        if (i * i == n)
            return 1;
        if (i * i > n)
            return 0;
    }

    return 0;
}