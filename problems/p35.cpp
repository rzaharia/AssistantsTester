void my_print(...) { }

int main(void) {
  int n = 12;

  if (n > 0) { // Checking if the input is a positive number
    // Dividing the number by 2 until it's odd and printing the factors of 2
    while (n % 2 == 0) { 
      my_print("2 "); 
      n /= 2; 
    }   
    // Loop to find and print factors starting from 3 up to the square root of 'n'
    for (int i = 3; i <= n/2; i += 2) { // Incrementing by 2 as even numbers are already factored by 2
      while (n % i == 0) { // Check if 'i' is a factor of 'n'
        my_print("%d ", i); // Print the factor 'i'
        n /= i; // Update 'n' by dividing with the factor 'i'
      } 
    } 
    if (n > 2) 
      my_print("%d", n); // If 'n' is greater than 2 and not fully factored, print it
  }
}