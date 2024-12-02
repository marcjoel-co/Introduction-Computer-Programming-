#include <stdio.h>

// Function prototypes
int get_valid_number(); 
char get_valid_operator();
void perform_operation(int num1, int num2, char operator);

int main() {
    int num1, num2;
    char operator;

    // Get two valid integers from the user
    printf("Enter the first number: ");
    num1 = get_valid_number();
    printf("Enter the second number: ");
    num2 = get_valid_number();

    // Get a valid operator from the user
    operator = get_valid_operator();

    // Perform the operation and display the result
    perform_operation(num1, num2, operator);

    return 0;
}

// Function to get a valid integer from the user
int get_valid_number() {
    int num;
    char term;
    while (scanf("%d%c", &num, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); // Clear invalid input
        printf("Invalid input. Please enter a valid integer: ");
    }
    return num;
}

// Function to get a valid operator from the user
char get_valid_operator() {
    char operator;
    printf("Enter an operator (+, -, *, /): ");
    while (scanf(" %c", &operator) != 1 || (operator != '+' && operator != '-' && operator != '*' && operator != '/')) {
        while (getchar() != '\n'); // Clear invalid input
        printf("Invalid operator. Please enter one of (+, -, *, /): ");
    }
    return operator;
}

// Function to perform the specified operation
void perform_operation(int num1, int num2, char operator) {
    if (operator == '+') {
        printf("Result: %d\n", num1 + num2);
    } else if (operator == '-') {
        printf("Result: %d\n", num1 - num2);
    } else if (operator == '*') {
        printf("Result: %d\n", num1 * num2);
    } else if (operator == '/') {
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed.\n");
        } else {
            printf("Result: %.2f\n", (float)num1 / num2);
        }
    } else {
        printf("Error: Invalid operator encountered. This should never happen!\n");
    }

}
