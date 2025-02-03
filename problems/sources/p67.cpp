int main() {
    int num = 32;
    int result = num > 0 && (num & (num - 1)) == 0;
    return result;
}