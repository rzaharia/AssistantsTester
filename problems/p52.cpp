int main()
{
    int number = 152; // 153 is Armstrong Armstrong narcissistic number, pluperfect digital invariant, or PPDI)
    // is a number that is equal to the sum of its digits raised to the power of the number of digits.
    int aux = number;
    int sum = 0;
    int digits = 0;

    while (aux != 0)
    {
        aux /= 10;
        digits++;
    }

    // Calculate the sum of digits raised to the power of the number of digits
    aux = number;
    while (aux > 0)
    {
        int digit = aux % 10;
        int digit_val = 1;
        for (int i = 0; i < digits; i++)
            digit_val *= digit;
        // sum += pow(digit, digits); // Raise digit to the power of 'digits'
        sum += digit_val;
        aux /= 10;
    }

    // Check if the calculated sum matches the original number
    return sum == number;
}