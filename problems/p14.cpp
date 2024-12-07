#include <stdio.h>
#include <stdlib.h>

// Function to count the number of set bits (1s) in the binary representation of numbers from 0 to 'num'
int main(void) {
    int returnSize,num=5;
    int buffer[6];
    int *p = buffer;
    int  i;
    // Allocate memory for the array to store the count of set bits
    returnSize = num + 1; // Set the return size to 'num + 1'

    p[0] = 0; // The count of set bits in 0 is 0
    for (i = 1; i <= num; i++) {
        // Use bitwise manipulation to count the set bits for each number
        // Count the number of set bits by using the formula: p[i] = p[i & (i - 1)] + 1
        p[i] = p[i & (i - 1)] + 1;
    }
    return returnSize;
}
