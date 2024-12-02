#include <stdio.h>

/* This program checks if a given number is positive, negative, or zero.
 * It prompts the user for a number and validates the input to ensure
 * it is a valid integer. The program then uses an if-else if-else
 * construct to determine whether the number is positive, negative, or zero,
 * and prints the corresponding message.*/

// Function prototype for input validation and for  checking the sign of the number
int getIntegerInput();
void checkNumberSign(int number);

// Main function
int main() {
    int number;

    // Get validated integer input from the user
    number = getIntegerInput();

    // Call the function to check if the number is positive, negative, or zero
    checkNumberSign(number);

    return 0;
}

int getIntegerInput() {
    int number;
    char term; // To capture any leftover characters

    while (1) {
        printf("Enter a number: ");
        if (scanf("%d%c", &number, &term) != 2 || term != '\n') {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid integer.\n");
        } else {
            // Valid input received
            break;
        }
    }
    return number;
}

void checkNumberSign(int number) {
    if (number > 0) {
        printf("Positive\n");
    } else if (number < 0) {
        printf("Negative\n");
    } else {
        printf("Zero\n");
    }
}