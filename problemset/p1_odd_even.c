#include <stdio.h>

// Function prototype for input validation and checking even or odd
int getIntegerInput();
void checkEvenOrOdd(int number);

// Main function
int main() {
    int number;

    // Get validated integer input from the user
    number = getIntegerInput();

    // Call the function to check if the number is even or odd
    checkEvenOrOdd(number);

    return 0;
}

int getIntegerInput() {
    int number;
    char term; // To capture any leftover characters

    while (1) {
        printf("Enter an integer: ");
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

void checkEvenOrOdd(int number) {
    if (number % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
}