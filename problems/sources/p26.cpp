#include <stdio.h>
#include <math.h>

int main() {
    int n = 8;

    // Manual square root calculation
    int s = 0;
    while (s * s <= n * 5 * n + 4) {
        s++;
    }
    s--;
    if (s * s == n * 5 * n + 4) {
        return 0;
    }

    s = 0;
    while (s * s <= n * 5 * n - 4) {
        s++;
    }
    s--;
    if (s * s == n * 5 * n - 4) {
        return 0;
    }
    return 1;
}
