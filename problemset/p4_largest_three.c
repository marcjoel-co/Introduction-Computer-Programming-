#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * This program accepts three numbers from the user and determines
 * which one is the largest using nested if statements.
 * It then prints the largest number.
 */

// Function prototypes
int findLargest(int num1, int num2, int num3);
int getValidInteger(const char *prompt);

// Main function
int main() {
    // Prompt user for input
    printf("Enter three numbers:\n");

    // Get valid integers from the user
    int num1 = getValidInteger("Number 1: ");
    int num2 = getValidInteger("Number 2: ");
    int num3 = getValidInteger("Number 3: ");

    // Find and print the largest number
    int largest = findLargest(num1, num2, num3);
    printf("The largest number is: %d\n", largest);

    return 0;
}

int findLargest(int num1, int num2, int num3) {
    int largest;

    // Determine the largest number using nested if statements
    if (num1 >= num2) {
        if (num1 >= num3) {
            largest = num1; // num1 is the largest
        } else {
            largest = num3; // num3 is the largest
        }
    } else {
        if (num2 >= num3) {
            largest = num2; // num2 is the largest
        } else {
            largest = num3; // num3 is the largest
        }
    }

    return largest; // Return the largest number
}

int getValidInteger(const char *prompt) {
    char input[100]; // Buffer to hold user input
    int number;
    char *endptr;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin); // Read a line of input

        // Attempt to convert the input to an integer
        number = strtol(input, &endptr, 10);

        // Check if the entire input was a valid integer
        if (endptr != input && *endptr == '\n') {
            return number; // Return the valid integer
        } else {
            printf("Invalid input. Please enter an integer.\n");
        }
    }
}