int main()
{
    int n = 42;
    int sum = 0;
    for (int i = 1; i < n/2; i++)
    {
        if (n % i == 0) // Check if 'i' is a divisor of 'n'
        {
            if (n / i == i)
                sum = sum + i; // If 'i' is a divisor and is equal to the square root of 'n', add it to 'sum'
            else
            {
                sum = sum + i; // Add 'i' to 'sum'
                sum = sum + (n / i); // Add 'n / i' to 'sum'
            }
        }
    }
    sum = sum - n; // Subtract the number 'n' from the sum of its divisors
    return sum; // Return the sum of divisors
}