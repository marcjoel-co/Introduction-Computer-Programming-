/* A program to automate the calculation of a circles area and circumference based on the radius; prompts the 
    user for the radius, calculates, and prints the area and circumference with a simple validation checker.*/

// 1: Start
#include <stdio.h>

// 2: begin by initalizing variables for later
float pi = 3.14;
int radius;

int main() {
    // 3: Get input from the user
   do {
        printf("Please input a positive integer forthe radius of the circle: ");
        scanf("%d", &radius);
    } while (radius <= 0);

    // 4: Calculate area and circumference
    float circumference = 2 * radius * pi; 
    float area = pi * (radius * radius);

    // 5: Display the area and circumference
    printf("The Area of your circle is %.02f and its circumference is %.02f ", area, circumference);

    //6: End
    return 0;
}
