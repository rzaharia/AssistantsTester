#include <stdio.h>

// Function to count the total number of occurrences of digit 1 in numbers up to the given limit
int main(void) {
    int n = 12;
        int m = 0, k = 0, x = 0, base = 1;

    // Loop to iterate through each digit of the number
    while (n > 0) {
        k = n % 10; // Get the current digit
        n = n / 10; // Update the number by removing the last digit

        // Count occurrences of digit 1 based on the current digit
        if (k > 1) {
            x += (n + 1) * base; // Increment occurrences if the digit is greater than 1
        } else if (k < 1) {
            x += n * base; // Increment occurrences if the digit is less than 1
        } else {
            x += n * base + m + 1; // Increment occurrences if the digit is equal to 1
        }

        m += k * base; // Update the count of occurrences so far
        base *= 10; // Update the base for the next digit
    }
    return x; // Return the total count of digit 1 occurrences
}
