#include <stdio.h>
#include <stdlib.h>

#define MY_ABS(x) x < 0 ? -x : x

void my_print(...) { }

// Main function
int main(void) {
    // Declare and initialize the variable 'n' to find its prime factors
    int n = 75; // The number for which prime factors are to be found
    // Check if the number 'n' is greater than 0 before finding its prime factors
    if (n > 0) {
        // Extract all the factors of 2
        while (n % 2 == 0) {
            my_print("2 "); // Print '2' as a prime factor
            n /= 2; // Divide 'n' by 2
        }

        // Check for odd factors starting from 3
        for (int i = 3; i <= n/2; i += 2) {
            // Check if 'i' is a factor of 'n'
            while (n % i == 0) {
                my_print("%d ", i); // Print 'i' as a prime factor
                n /= i; // Divide 'n' by 'i'
            }
        }

        // If 'n' is greater than 2 and has a prime factor > sqrt(n)
        if (n > 2) {
            my_print("%d ", n); // Print 'n' as a prime factor
        }
    }
    return 0; // End of the main function
}
