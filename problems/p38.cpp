
int main(void) {
  int num = 5;
    int result = 0;
    for (int i = 1; i <= num; i++) {
        int temp = i, sum = 0;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum % 2 != 0) {
            result++;
        }
    }
    return result; 
}