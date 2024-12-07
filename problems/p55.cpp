int main() {
    double principal, rate, time;

    double calculateSimpleInterest = (principal * rate * time) / 100.0;

    double result = 1.0;
    double base = 1 + rate / 100.0;
    for (int i = 0; i < time; ++i) {
        result *= base;
    }

    double calculateCompoundInterest = principal * result - principal;
    
    return principal;
}