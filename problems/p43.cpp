int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0, high = n - 1, mid;
    bool found = false;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            found = true;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return found == false;
}