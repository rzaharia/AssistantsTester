#include <stdio.h>

int main(void)
{
    int n=123, d, y = 0;

    // Reversing the digits of the integer
    while (n) {
        d = n % 10;
        y = y * 10 + d;  // Update the reversed integer
        n = n / 10;      // Move to the next digit
    }

    return y;  // Return the reversed integer
}
