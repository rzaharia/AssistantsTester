// Function to count the number of digits in 'n' that evenly divide 'n'
int main()
{
    int n = 5;
    int temp = n; // Temporary variable to store 'n'
	int result = 0; // Variable to store the count of digits that divide 'n'

    // Loop to iterate through each digit of 'n'
    while(temp != 0){    	
        int d = temp % 10; // Extract the rightmost digit of 'temp'
        temp /= 10; // Move to the next digit by dividing 'temp' by 10

        // Check if 'n' is divisible by the extracted digit 'd'
        if(n % d == 0)
            result++; // Increment the count if 'n' is divisible by 'd'
    }
    return result; // Return the total count of digits that divide 'n'
}