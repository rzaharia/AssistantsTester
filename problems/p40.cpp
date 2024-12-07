#define MY_MIN(a,b) (a > b) ? b : a

int main() {
    int a = 51, b = 231;

    int gcd = 1;
    for (int i = 1; i <= MY_MIN(a, b); ++i) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    int lcm = (a * b) / gcd;
    return lcm;
}