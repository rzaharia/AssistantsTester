#include <stdio.h>

// Function to count the number of trailing zeroes in the factorial of a number
int main(void) {
    int n = 4;
    int number = 0;

    // Loop to calculate the number of trailing zeroes
    while (n > 0) {
        number += n / 5; // Count how many multiples of 5 are present in the factorial
        n /= 5; // Divide the number by 5 to check for the next multiple of 5
    }

    return number; // Return the count of trailing zeroes
}
