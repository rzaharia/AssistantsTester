#include <stdio.h>

// Function to calculate the square root of a number using the Babylonian method
int main(void) { 
    int n = 50; 
    float a = n; // Initial value for 'a' is the number itself
    float b = 1; // Initial value for 'b' is 1
    double e = 0.000001; // Threshold for the difference between 'a' and 'b'

    // Loop to approximate the square root using the Babylonian method
    while (a - b > e) { 
        a = (a + b) / 2; // Update 'a' by averaging 'a' and 'b'
        b = n / a; // Calculate 'b' as the number divided by the updated 'a'
    } 

    return (int)a; // Return the calculated square root 
}
