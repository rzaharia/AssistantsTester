int main()
{
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;
    bool sorted = true;

    for (int i = 1; i < len; i++)
        if (nums[i] < nums[i - 1])
        {
            sorted = false;
            break;
        }

    return 0;
}