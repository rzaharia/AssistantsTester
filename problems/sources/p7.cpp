int main() {
    int n = 30, a = 0, b = 1, c = 0;

    while (c <= n) {
        if (c == n) {
            return 0;
        }
        c = a + b;
        a = b;
        b = c;
    }

    return 1;
}