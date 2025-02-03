int main()
{
    char buffer[10] = "123456789";
    int len = 9;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (buffer[i] == 'a' || buffer[i] == 'e' ||
            buffer[i] == 'i' || buffer[i] == 'o' ||
            buffer[i] == 'u')
        {
            ++count;
        }
    }
    return count;
}