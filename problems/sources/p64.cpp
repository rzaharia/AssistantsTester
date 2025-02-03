int main()
{
    char buffer[10] = "123456789";
    int len = 9;
    for (int i = 0; i < len; i++)
    {
        if (buffer[i] == ' ')
            buffer[i] = '0';
        char c = buffer[i];
        if (c == ' ' || c == '\r' || c == '\n' || c == '\t')
            return 1;
    }

    return 0;
}