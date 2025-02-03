#include <stdio.h>

// Function to find the Nth digit in a sequence
int main(void) {
    int n = 7;
    unsigned int i, j, k;
    i = j = 1;

    // Loop to find the appropriate position of the digit in the sequence
    while (n > 9 * i * j) {
        n -= 9 * i * j; // Decrement n based on the sequence length
        j *= 10; // Increase j to move to the next digit length
        i++; // Increment i to keep track of digit length
    }

    k = j + (n - 1) / i; // Calculate the position of the digit in the sequence

    // Loop to extract the desired digit
    for (j = (n - 1) % i; j < i - 1; j++) {
        k = k / 10; // Move to the specific digit position
    }

    return k % 10; // Return the Nth digit
}
