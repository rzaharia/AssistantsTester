void my_print(...) { }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = 0, end = n - 1;

    while (start < end) {
        int aux = arr[start];
        arr[start] = arr[end];
        arr[end] = aux;
        start++;
        end--;
    }

    for (int i = 0; i < n; ++i) {
        my_print("%d",arr[i]);
    }

    return 0;
}