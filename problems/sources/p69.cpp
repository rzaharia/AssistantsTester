int main()
{
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;
    int result;
    if (len == 1)
    {
        return -1;
    }
    else if (len == 2)
    {
        result = nums[1];
        return result;
    }
    int largest = nums[0], secondLargest = nums[1];
    for (int i = 0; i < len; i++)
    {
        int num = nums[i];
        if (num > largest)
        {
            secondLargest = largest;
            largest = num;
        }
        else if (num > secondLargest && num < largest)
        {
            secondLargest = num;
        }
    }
    result = secondLargest;
    return result;
}