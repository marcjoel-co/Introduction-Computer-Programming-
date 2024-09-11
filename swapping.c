//start
#include <stdio.h>

//initialize variables
char a;
char b;
char c;

int main(void) {
    //get necessary variables from user
    printf("Please enter variable (single character) A: ");
    scanf("%s", &a);
    getchar();
    printf("Please enter variable (single character) B: ");
    scanf("%s", &b);

    // Step 3 process
    c = a;
    a = b;
    b = c;
    // display the result
    printf("\n\t\tThe value of the first variable(A) in now: %c  \n\t\tThe value of the second variable(B) is now: %c\n", a, b);
    
    //end : note to self return zero means successful return otherwise return any other number means false
    return 0;

}