int main()
{
    char buffer[10] = "123456789";
    int len = 9;
    for (int i = 0; i < len; i++)
    {
        char c = buffer[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') || c == '+' || c == '/' || c == '='))
        {
            return 0;
        }
    }
    return 1;
}