void my_print(...) { }

int main() {
    int n = 12;

    int count = 0, num = 2;

    while (count < n) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            my_print("%d", num);
            count++;
        }

        num++;
    }

    return 0;
}