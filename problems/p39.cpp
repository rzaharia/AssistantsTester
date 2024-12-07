int main() {
    int a=12, b=52;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}