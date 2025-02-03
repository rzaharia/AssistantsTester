int main() {
    int num = 234;
    int sum = 0, temp = num;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return num % sum == 0;
}