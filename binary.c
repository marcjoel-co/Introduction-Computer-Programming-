/* 
* This is a program that converts decimal numbers into its binary form it
* works by  appending the remainder to an array. the validation system works
* by having an additonal copy of decimal then converting it into a string then
* it checks if that string is between 0 and 9
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max_char 64 // defining the value of an array 

int main() {
    // Step 1: Declare the necessary variables.
    int decimal = 0, remainder = 0, i = 0;
    char binary[max_char], input[max_char];

    // Step 2: Input variables
    printf("Enter a decimal number: ");
    fgets(input, max_char, stdin); // Use fgets to read input as string

    // Step 3: Check if the input is a valid decimal number (between '0' and '9')
    for (int j = 0; j < strlen(input) - 1; j++) { // -1 to exclude the newline character
        if (input[j] < '0' || input[j] > '9') {
            printf("Invalid input! Please enter a valid decimal number.\n");
            return 0;
        }
    }  
    

    // Step 4: Convert the string input to integer
    decimal = 0;
    for (int j = 0; j < strlen(input) - 1; j++) {
        decimal = decimal * 10 + (input[j] - '0'); // Convert char to integer
    }

    // Step 5: Check for where the number is 0.
    if (decimal == 0) {
        printf("The binary equivalent is: 0\n");
        return 0;
    }

    // Step 6: Loop to convert decimal to binary
    while (decimal > 0) {
        remainder = decimal % 2;     // Get the remainder when dividing by 2
        binary[i] = remainder + '0'; // Store the remainder as a binary digit
        i++;                         // Increment for the next position
        decimal = decimal / 2;       // Divide the decimal number by 2 (integer division)
    }
    binary[i] = '\0'; // Null-terminate the string

    // Step 7: Print the binary string in reverse order
    printf("The binary equivalent is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
    printf("\n");

    return 0;
}bina
