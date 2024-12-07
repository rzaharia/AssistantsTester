#include <stdio.h>
#include <stdlib.h>

// Function to calculate the exponential function using Taylor series approximation
int main(void) {
    int n = 25; // Number of terms for Taylor series
    float x = 5.0; // Value of x in e^x
        float exp_sum = 1; // Initialize the sum as 1 (initial term of Taylor series)

    // Loop to calculate each term of the Taylor series for the exponential function
    for (int i = n - 1; i > 0; --i) {
        exp_sum = 1 + x * exp_sum / i; // Calculate the next term of the series and update the sum
    }

    return (int)exp_sum; // Return the final result of the Taylor series approximation for e^x
}
