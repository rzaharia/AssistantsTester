int main()
{
    char buffer[10] = "123456789";
    int len = 9;
    for (int i = 0; i < len; i++)
    {
        if (buffer[i] == 'a' || buffer[i] == 'e' ||
            buffer[i] == 'i' || buffer[i] == 'o' ||
            buffer[i] == 'u')
        {
            buffer[i] = '0';
        }
    }

    return 0;
}