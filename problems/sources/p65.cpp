int main()
{
    int n = 32;
    int a = 1;
    bool found = false;
    while (a < n)
    {
        a = a * 2;
        if (a == n)
        {
            found = true;
            break;
        }
        a++;
    }
    return found == false;
}