
#define MY_MIN(a,b) (a > b) ? b : a;
#define MY_MAX(a,b) (a < b) ? b : a;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_val = arr[0];
    int min_val = arr[0];

    for (int i = 1; i < n; ++i) {
        max_val = MY_MAX(max_val, arr[i]);
        min_val = MY_MIN(min_val, arr[i]);
    }
    return 0;
}