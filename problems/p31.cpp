// Function to find the largest number by swapping two digits
int main(){
    int num = 4;

    int digits[10] = {0};
    int n = 0;

    // Extract digits and count their occurrences
    while (num > 0) {
        int digit = num % 10;
        digits[digit]++;
        num /= 10;
        n++;
    }

    // Find the first digit (from the right) that can be increased
    int i = n - 1;
    while (i > 0 && digits[i] == 0) {
        i--;
    }

    // If no such digit is found, the number is already in descending order
    if (i == 0 && digits[0] == 0) {
        return num;
    }

    // Decrease the current digit and increase the next larger digit
    digits[i]--;
    int j = i + 1;
    while (j < 10 && digits[j] == 0) {
        j++;
    }
    digits[j]++;

    // Construct the largest number from the digit counts
    int largestNum = 0;
    for (int k = 9; k >= 0; k--) {
        while (digits[k] > 0) {
            largestNum = largestNum * 10 + k;
            digits[k]--;
        }
    }

    return largestNum;
}
