#define MY_MIN(a,b) (a > b) ? b : a;

int main()
{
    int m = 3; // Initialize m
    int n = 3; // Initialize n
    int k = 8; // Initialize k
    if ((k < 1) || (k > m * n)) // Check if k is out of range
    return 0; // Return 0 if k is out of range (false)

    int s, p, mid, t; // Declare variables for binary search
    s = 1, p = n * m; // Initialize start and end points for binary search

    // Binary search to find the kth smallest element
    while (s <= p) {
        mid = s + (p - s) / 2; // Calculate the middle element without floor division
        t = 0; // Initialize t to 0

        // Loop through each row of the multiplication table
        for (int i = 1; i <= m; i++) {
            t += MY_MIN(mid / i, n); // Calculate the number of elements less than or equal to mid in the current row
        }

        if (t >= k) {
            p = mid - 1; // Update end point if the count is greater than or equal to k
        } else {
            s = mid + 1; // Update start point if the count is less than k
        }
    }
    return s; // Return the kth smallest element

    return 0;
}