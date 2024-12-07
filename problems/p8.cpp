#include <stdio.h>

// Function to convert a column number to an Excel column title
int main(void) {
    int column_no = 3;
    char title[1024]; // Allocate memory to store the Excel column title
    char * result = (char*)title;

        if (column_no <= 0) {
        return 0; // Return an empty string for invalid column numbers
    }

    int len = 0;

    // Loop to convert column number to Excel column title
    do {
        result[len++] = ((column_no - 1) % 26) + 'A'; // Get the character corresponding to the column number
        column_no = (column_no - 1) / 26; // Update column number for the next iteration
    } while (column_no > 0);

    result[len] = '\0'; // Null-terminate the resulting string

    // Reverse the characters in the string to get the correct Excel column title
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char c = result[i];
        result[i] = result[j];
        result[j] = c;
    }
    return 0; // Return the Excel column title string
}
