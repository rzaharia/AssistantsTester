#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Main function to test the is_Number function with different strings
int main(void) {	
    char* str1 = (char*)"1234";
        int n, m;

    // Skip leading spaces
    while (*str1 == ' ') str1 ++;

    n = m = 0;

    // Skip the sign of the number
    if (*str1 == '+' || *str1 == '-') str1 ++;

    // Loop to check for digits before a possible decimal point
    while (*str1 >= '0' && *str1 <= '9') {
        n ++;
        str1 ++;
    }

    // Check if there is a decimal point
    if (*str1 == '.') {
        str1 ++;
        // Loop to check for digits after the decimal point
        while (*str1 >= '0' && *str1 <= '9') {
            m ++;
            str1 ++;
        }
        // If no digits found before or after the decimal point, return false
        if (!n && !m) return false;
    } else if (!n) {
        // If no digits found before a decimal point, return false
        return false;
    }

    // Check for exponent notation (e.g., 1.23e45)
    if (*str1 == 'e' || *str1 == 'E') {
        str1 ++;
        // Check for sign after 'e' or 'E'
        if (*str1 == '+' || *str1 == '-') str1 ++;
        n = 0;
        // Loop to check for digits in the exponent
        while (*str1 >= '0' && *str1 <= '9') {
            n ++;
            str1 ++;
        }
        // If no digits found in the exponent, return false
        if (!n) return false;
    }

    // Skip trailing spaces
    while (*str1 == ' ') str1 ++;

    // Return true if the entire string has been checked and no invalid characters found
    return *str1 == 0 ? true : false;
}
