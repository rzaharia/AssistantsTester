#include <stdio.h> // Including standard input-output library
#include <math.h> // Including math library for pow function
#include <stdlib.h> // Including standard library for exit function


int main() {
    int n = 12;

    if (n == 2) {
        return 1;
    } else if (n == 3) {
        return 2;
    } else if (n % 3 == 0) {
        int result = 1;
        for (int i = 0; i < n / 3; i++) {
            result *= 3;
        }
        return result;
    } else if (n % 3 == 1) {
        int result = 4;
        for (int i = 0; i < (n - 4) / 3; i++) {
            result *= 3;
        }
        return result;
    } else {
        int result = 2;
        for (int i = 0; i < n / 3; i++) {
            result *= 3;
        }
        return result;
    }
}

