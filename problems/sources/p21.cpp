#include <stdio.h>
#include <stdlib.h>

// Function to compute streaming average of an array
int main(void) { 
    float arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Array of floating point numbers
    int arr_size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
        float avg = 0; // Variable to store the average
    int i = 0;

    // Loop through the array to compute streaming averages
    while (i < arr_size) { 
        avg = (avg * i + arr[i]) / (i + 1); // Update the average value
        //my_print("\nAverage of %d numbers is %f \n", i + 1, avg); // Print the streaming average
        i++;
    } 
    return avg; // End of function
}
