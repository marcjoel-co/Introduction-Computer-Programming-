#include <stdio.h>

// Function prototypes
int get_valid_positive_integer();
int is_valid_triangle(int a, int b, int c);
void determine_triangle_type(int a, int b, int c);

int main() {
    int side1, side2, side3;

    // Get three valid positive integers for the sides
    printf("Enter the first side of the triangle: ");
    side1 = get_valid_positive_integer();
    printf("Enter the second side of the triangle: ");
    side2 = get_valid_positive_integer();
    printf("Enter the third side of the triangle: ");
    side3 = get_valid_positive_integer();

    // Validate and determine the triangle type
    if (is_valid_triangle(side1, side2, side3)) {
        determine_triangle_type(side1, side2, side3);
    } else {
        printf("The given sides do not form a valid triangle.\n");
    }

    return 0;
}

// Function to get a valid positive integer from the user
int get_valid_positive_integer() {
    int num;
    char term;
    while (scanf("%d%c", &num, &term) != 2 || term != '\n' || num <= 0) {
        while (getchar() != '\n'); // Clear invalid input
        if (num <= 0) {
            printf("Sides must be positive integers. ");
        }
        printf("Please enter a valid positive integer: ");
    }
    return num;
}

// Function to check if three sides form a valid triangle
int is_valid_triangle(int a, int b, int c) {
    // Check triangle inequality: sum of any two sides > third side
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Function to determine the type of triangle
void determine_triangle_type(int a, int b, int c) {
    if (a == b && b == c) {
        printf("The triangle is Equilateral.\n");
    } else if (a == b || b == c || a == c) {
        printf("The triangle is Isosceles.\n");
    } else {
        printf("The triangle is Scalene.\n");
    }
}
