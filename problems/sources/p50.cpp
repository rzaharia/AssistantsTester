int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }

    int max_count = 0, mode = arr[0], current_count = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count; 

                mode = arr[i - 1];
            }
            current_count = 1;
        }
    }

    if (current_count > max_count) {
        max_count = current_count;
        mode = arr[n - 1];
    }

    return mode;
}