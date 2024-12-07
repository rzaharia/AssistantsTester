#include <stdio.h>
#include <stdlib.h>

// Function to generate the next smallest palindrome after 'n'
int main(void)
{          
    int n = 121; // Declare and initialize n to 121
    int ans=1, digit, rev_num=0, num; // Declare variables ans, digit, rev_num, and num              
    if(n<10) // Check if n is less than 10
    {   
        ans=0; // Set ans to 0
        return n+1; // Return n+1 as the next smallest palindrome
    }
    num=n; // Store the original value of n
    while(ans!=0) // While loop until ans is not 0
    {   
        rev_num=0; // Initialize rev_num to 0
        digit=0; // Initialize digit to 0
        n=++num; // Increment num and assign to n

        while(n>0) // While loop to reverse the number and store it in rev_num       
        {
            digit=n%10; // Get the last digit of n
            rev_num=rev_num*10+digit; // Append digit to rev_num
            n=n/10; // Remove the last digit from n
        }
        if(rev_num==num) // Check if the reversed number is equal to the original number   
        {
            ans=0; // Set ans to 0
            return num; // Return the palindrome number
        }
        else 
            ans=1; // Set ans to 1 to continue the loop
    }
    return num; // Return the next palindrome number
}
