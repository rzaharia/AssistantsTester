#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is a palindrome
int main()
{
    int i = 1221;
    int n, d, y = 0;

    // Check if the number is negative; negative numbers cannot be palindromes
    if (i < 0) 
        return false;

    n = i;
    // Reverse the number and compare it with the original number
    while (n) {
        d = n % 10;

        // Check for potential overflow
        if (y > (0x7fffffff - d) / 10) 
            return false;   // Return false if overflow is detected

        y = y * 10 + d;  // Reverse the number
        n = n / 10;      // Move to the next digit
    }

    return (y == i);  // Return true if the reversed number is equal to the original number
}