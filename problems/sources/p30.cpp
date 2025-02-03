#include <stdio.h> // Include standard input-output library

#define MY_MIN(a,b) (a > b) ? b : a;

// Function to calculate the number of unique digits in a range
int main(void) {
    int n = 1; // Declare and initialize n to 1
    if(n == 0)
        return 1; // If n is 0, return 1 as there is only one unique digit (0)
    
    n = MY_MIN(10, n); // Limit n to be at most 10
    
    if(n == 1)
        return 10; // If n is 1, return 10 as there are 10 unique digits (0-9)
    
    int flag = 9; // Initialize flag to 9
    int result = 10; // Initialize result to 10
    
    // Loop to calculate the number of unique digits in the range
    for(int i = 2; i <= n; i++){
        flag *= (9 - i + 2); // Update flag based on the number of remaining digits
        result += flag; // Add the updated flag to the result
    }
    return result; // Return the total number of unique digits
}
