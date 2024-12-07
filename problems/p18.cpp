#include <stdio.h>

// Function to check the total number of full staircase rows based on a given number of blocks 'n'
int main(void) {
    int n = 5;
        if (n < 0) return -1; // Return -1 if the input 'n' is negative
    if (n == 0) return 0; // Return 0 if the input 'n' is zero

    int rows = 0; // Variable to keep track of the number of rows
    long sum = 0; // Variable to store the sum of blocks in each row

    // Loop to calculate the total number of full staircase rows based on 'n'
    while (sum <= n) {
        sum += rows + 1; // Increment the sum by the number of blocks in the next row
        rows++; // Increment the row count
    }

    return rows - 1; // Return the total number of full staircase rows
}
