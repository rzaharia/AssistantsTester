#include <stdio.h>
#include <stdlib.h>

// Function to find the number of square numbers required to sum up to 'n'
int main(void) {
  int n = 14;
  int buffer[15];
  int *nums = buffer;
    nums[0] = 0;

  // Dynamic programming approach to find the minimum number of square numbers needed
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
      // Update nums[i] with the minimum of the current value and nums[i - j*j] + 1
      nums[i] = nums[i] < nums[i - j * j] + 1 ? nums[i] : nums[i - j * j] + 1;
    }
  }

  // Return the minimum number of square numbers required to sum up to 'n'
  return nums[n];
}
