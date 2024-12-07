#include <stdio.h>
#include <limits.h>

// Function to perform integer division without using the '/' operator
int main(void)
{
    // Test cases for the divide_result function
    int dividend_num = 7;
    int divisor_num = 2;
        int sign = 1; // Variable to hold the sign of the result
    long int output = 0; // Variable to store the result of division

    // Handling sign of the numbers and converting to negative if necessary
    if (dividend_num < 0) {
        sign *= -1;
    } else {
        dividend_num *= -1;
    }

    if (divisor_num < 0) {
        sign *= -1;
    } else {
        divisor_num *= -1;
    }

    // Performing division using subtraction
    while (dividend_num <= divisor_num) {
        long int temp = 0;
        long int div = divisor_num;

        // Repeatedly subtracting divisor from dividend until dividend is smaller
        while (dividend_num <= div) {
            temp += (temp + 1);
            dividend_num -= div;
            div += div;
        }

        // Checking for overflow and returning INT_MIN or INT_MAX accordingly
        if (output >= INT_MAX) {
            if (sign == -1) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }

        output += temp; // Adding the calculated value to the result
    }

    return output * sign; // Return the final result with proper sign
}
