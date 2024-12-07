#include <stdio.h>

// Function to calculate power of x raised to the power n (x^n)
int main(void)
{
    double x = 7.0;
    int n = 2;
    double k = 1.0;

    // Handle negative exponents
    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }

    // Iteratively calculate the power
    while (n > 0) {
        if (n % 2 == 1) {
            k *= x;
        }
        x *= x;
        n /= 2;
    }

    return (int)k; // Return the computed value of x^n
}
