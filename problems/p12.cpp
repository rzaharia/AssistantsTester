#include <stdio.h>

// Function to calculate the digital root of a number (single-digit sum)
int main(void) {
    int num = 12;
    return num - (num - 1) / 9 * 9;
}
