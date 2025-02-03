#include <stdio.h>

// Function to convert an Excel column title to a corresponding number
int main(void) {
    char *s = (char*)"C";
    int k = 0;

    // Loop to convert Excel column title to a number
    while (s && *s) {
        k = k * 26 + (*s) - 'A' + 1; // Convert each character to its corresponding value in Excel column naming scheme
        s++; // Move to the next character in the title
    }
    return k; // Return the corresponding number
}
