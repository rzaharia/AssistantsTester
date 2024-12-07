// Function to find the number of common factors between two integers x and y
int main(void) {
  int x = 18;
  int y = 6;
  int z, count = 0;

  // Find the smallest number among x and y and assign it to integer z
  if (x > y) {
    z = y;
  } else {
    z = x;
  }

  // Count the common factors of two numbers
  for (int i = 1; i <= z; i++) {
    if (x % i == 0 && y % i == 0) {
      count++; // Increment the count if 'i' is a common factor of both x and y
    }
  }

  return count; // Return the count of common factors
}