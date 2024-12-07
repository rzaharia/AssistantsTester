int main(void) {
  int n = 135, ctr = 0, result;

  int len = 0, temp;
  int count = 0;
  int data[10] = {0};
  int n_copy = n;

  // Loop through integers from 1 to 'n' to count unique digits using the 'test' function
  for (int i = 1; i <= n; i++) {
    len = 0;
    count = 0;
    data[10] = {0};

    while (n_copy > 0) {
            n_copy /= 10;
            len++;
        }

    // Extract digits from 'n' and count their occurrences
    while (n > 0) {
        temp = n % 10;
        n /= 10;
        data[temp]++;
    }

    // Count unique digits (digits that occurred exactly once)
    for (int j = 0; j < 10; ++j) {
        if (data[j] == 1)
            count++;
    }

    // Check if the count of unique digits equals the length of 'n'
    if (count == len)
       result = len;
    else
        result = 0;

    if (result > 0) {
      ctr++; // Increment counter if unique digits are found
      result = 0;
    }
  }

  return ctr;
}