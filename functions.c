#include <stdio.h>


int add(int x,int y);
int subtract(int x, int y);
int multiply (int x, int y);
float divide (int x, int y);

int num1, num2;
int main() {
char ans = 'Y';

while (ans == 'Y' || ans == 'y') {
scanf("%i, %i", &a, &b);
printf("Addition result: %d\n", add(num1, num2));
printf("Subtraction result: %d\n", subtract(num1, num2));
printf("Multiplication result: %d\n", multiply(num1, num2));

if (b != 0) {
    printf("Division result: %f\n", divide(num1, num2));
} else {
    printf("Cannot divide by zero\n");
}

printf("Again? Y/N ");
scanf(" %c", &ans);


}
}

int add(int x,int y){
return x + y;
}

int subtract(int x, int y){
return x - y;
}

int multiply (int x, int y){
return x * y;
}

float divide (int x, int y){
if (y == 0) {
    return 0;
}
return (float)x / y;
}

