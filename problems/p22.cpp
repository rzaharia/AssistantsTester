#include <stdio.h>
#include <stdlib.h>

// Function to count the numbers without digit 7
int main() {
    int num = 10;
    int count = 0;
    for (int i = 1; i <= num; i++) {
        int temp = i;
        bool hasSeven = false;
        while (temp > 0) {
            if (temp % 10 == 7) {
                hasSeven = true;
                break;
            }
            temp /= 10;
        }
        if (!hasSeven) {
            count++;
        }
    }
    return count;
}