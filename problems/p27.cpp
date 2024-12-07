#include <stdio.h>
#include <math.h>

// Function to perform multiplication using bitwise operators
int main(void) {
    int x = 8; // First number for multiplication
    int y = 9; // Second number for multiplication
    // Adjust signs if both x and y are negative or if y is negative
    if (x < 0 && y < 0) {
        x = x * (-1);
        y = y * (-1);
    } else if (x > 0 && y < 0) {
        x = x * (-1);
        y = y * (-1);
    }

    int result = 0; // Initialize the result variable to store the product

    // Multiply using bitwise operations
    while (y > 0) {
        if ((y & 1) != 0) // If the least significant bit of y is set
            result = result + x; // Add x to the result
        x = x << 1; // Left shift x to multiply it by 2
        y = y >> 1; // Right shift y to divide it by 2
    }

    return result; // Return the final product
}
