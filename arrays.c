#include <stdio.h>

#define MAX_LENGTH 5

int mod(int array[]); 
void loop(int array[]);

int main() {

  int array[MAX_LENGTH] = {1, 2, 3, 4, 5};

  printf("Before calling the function, array: \n");
  
    //step 2: before the function.
    loop(array);
    mod(array);    
    
    // Step 5: Display the array after calling the function PRINT 
   
    printf("After calling the function, array: \n");
    loop(array);

   
    printf("\n");
}

int mod(int array[]) {

    printf("modify index1: ");
    scanf("%i", &array[1]);

    printf("modify index2: ");

    scanf("%i", &array[2]);
    printf("\n");
    // step 4: call in the inside the function 
    printf("the array  inside the function: \n");
    loop(array);
  

  printf("\n");

  return 0;
}

 
void loop(int array[]){

    for (int i = 0; i <  MAX_LENGTH; i++){
        printf("%i", array[i]);
    }
    printf("\n");
}

