#include <stdio.h>
#include <stdbool.h>

// check if a given integer is a power of three.
int main(void) {
    int n = 9;
    if (n <= 0) {
        return 0;
    }

    while (n % 3 == 0) {
        n /= 3;
    }

    return n == 1;
}
