#include <stdio.h> // Include standard input-output library
#include <math.h> // Include math library
#include <stdlib.h> // Include standard library

// Function to print numbers from 1 to n in lexicographic order
void my_print(...)
{ }

int main(void)
{
    int n = 10;
    	int m, j, i = 1; // Declare variables m, j, and i with initialization
    while(i<= 9){ // While loop to iterate over digits 1 to 9
        j = 1; // Initialize j to 1
        while( j <= n){ // Nested while loop to iterate over numbers less than or equal to n
            m = 0; // Initialize m to 0
			while(m < j) { // Nested while loop to iterate over digits 0 to j-1
                if((m + j * i)<= n){ // Check if the number formed is less than or equal to n
                    my_print("%d ", m + j * i); // Print the number
                }
                m=m+1; // Increment m
			  }
            j= j*10; // Update j to the next power of 10
        }
        i=i+1; // Increment i
    }
    return 0; // Return 0 to indicate successful execution
}

