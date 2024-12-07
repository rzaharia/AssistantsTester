#include <stdio.h>

// function to multiply two integers 'a' and 'b'
int main() {
    int a = 50;
    int b = 12;
    int result = 0;

    // Handle negative numbers
    if (b < 0) {
        a = -a;
        b = -b;
    }

    // Iterative multiplication using addition
    while (b > 0) {
        result += a;
        b--;
    }

    return result;
}