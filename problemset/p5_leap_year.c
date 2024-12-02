/*
    Leap Year Checker Program
    -------------------------
    This program prompts the user to enter a positive year and determines whether it is a leap year or not.
    A leap year is defined by the following rules:
    - A year is a leap year if it is divisible by 4 and not divisible by 100, or
    - A year is a leap year if it is divisible by 400.
    Input validation is performed to ensure the user enters only valid positive integers.
*/

#include <stdio.h>

// Function prototypes
int get_valid_positive_year();
int is_leap_year(int year);

int main() {
    int year;

    // Get a valid positive year from the user
    year = get_valid_positive_year();

    // Check if the year is a leap year
    if (is_leap_year(year)) {
        printf("Leap Year\n");
    } else {
        printf("Not a Leap Year\n");
    }

    return 0;
}

// Function to get a valid positive year from the user
int get_valid_positive_year() {
    int year;
    char term; // Variable to check for extra input after number
    printf("Enter a positive year: ");
    while (scanf("%d%c", &year, &term) != 2 || term != '\n' || year <= 0) {
        // Clear invalid input
        while (getchar() != '\n');
        if (year <= 0) {
            printf("Year must be a positive integer. ");
        }
        printf("Please enter a valid positive year: ");
    }
    return year;
}

// Function to determine if a year is a leap year
int is_leap_year(int year) {
    // Leap year logic: divisible by 4 and not 100, or divisible by 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
