int main() {
    int num = 1413;

    bool isPrime = true;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime && num > 1) {
        isPrime = true;
    } else {
        isPrime = false;
    }

    return isPrime == false;
}