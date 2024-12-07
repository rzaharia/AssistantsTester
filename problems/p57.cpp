int main(int n)
{
    if (n == 1)
        return 1; // If the number is 1, it's considered a Kaprekar number

    int sqr_n = n * n;  // Square of the number
    int ctr_digits = 0; // Counter for the number of digits in the square

    // Count the number of digits in the square of the number
    while (sqr_n)
    {
        ctr_digits++;
        sqr_n /= 10;
    }

    sqr_n = n * n; // Reset the square of the number

    // Loop to check for Kaprekar property
    for (int r_digits = 1; r_digits < ctr_digits; r_digits++)
    {
        int eq_parts = 1;
        for (int i = 0; i < r_digits; i++)
            eq_parts *= 10;
        // int eq_parts = pow(10, r_digits); // Calculate the divisor for splitting the square

        if (eq_parts == n)
            continue; // Skip when the divisor equals the number itself

        // Calculate the sum of the split parts of the square
        int sum = sqr_n / eq_parts + sqr_n % eq_parts;

        if (sum == n)
            return 1; // If the sum of split parts equals the number, it's a Kaprekar number
    }

    return 0; // If the conditions aren't met, it's not a Kaprekar number
}