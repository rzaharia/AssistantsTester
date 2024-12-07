int main()
{
    const char* s1 = (const char*)"123456789";
    const char* s2 = (const char*)"123456789";
    int len1 = 10;
    int len2 = 10;
    if (len1 != len2)
        return 0;

    int char_counts[26]; // Assuming only lowercase letters

    // Count character frequencies in s1
    while (*s1)
    {
        char_counts[*s1 - 'a']++;
        s1++;
    }

    // Decrement character frequencies in s2
    while (*s2)
    {
        char_counts[*s2 - 'a']--;
        if (char_counts[*s2 - 'a'] < 0)
        {
            return false;
        }
        s2++;
    }

    return true;
}