//Write a program to check whether a given integer can be expressed as the sum of any non-negative integer and its reverse. Return true otherwise false.
int main() {
    int n = 544;
    
    if (n == 0) return 1; // If the number is 0, it can be expressed as the sum of itself and its reverse (0)

    for (int i = n / 2; i < n; i++) { // Loop from n/2 to n-1 to find the sum of 'i' and its reverse equal to 'n'
        int rev = 0, t, r;
        for (t = i; i != 0; i /= 10) {
            r = i % 10; // Extracting the rightmost digit of 'i'
            rev = rev * 10 + r; // Building the reversed number
        }
        if (i + rev == n) { // Check if 'i' + its reverse equals 'n'
            return 1; // If found, return true
        }
    }
    return 0; // If no such 'i' exists, return false
}