/* This version uses functions instead of doing it straight through. according to cs50's ai this is more feasible on the long
term just to account for the growth of the program:> */
// start
#include <stdio.h>
#include <stdlib.h>

// 2 Initialize Global variables
int amount_exam = 10;
float passing_percent = 5.00;
int score = 0;
int ttl_score = 0;
int removal;

void exams();
void check_pass(int test, int pass_per);

int main() {
    // 2.1 Initialize each user value 
    // 2 Get inputs for each exam score
    exams();
    
    // Calculate the average score
    float average = (float)ttl_score / amount_exam;

    // Print the average score
    printf("Average score: %.2f\n", average);

    // Check if the average score meets the passing percentage
    check_pass(average, passing_percent);

    // Ask if the user wants to take the removal exam
    printf("Would you like to take the removal exam? (0 for yes, any other number for no): ");
    scanf("%i", &removal); // The assignment said it 'can' take the removal exam not 'have' to
    
    if (removal != 0) {
        printf("You chose not to take the removal exam.\n");
        return 0;
    }

    passing_percent += 1.00; // Increase benchmark for passing percentage

    // Use a do-while loop to repeatedly ask for the score until a valid one is entered
    do {
        printf("Insert your score for the removal exam: ");
        scanf("%i", &score);

        if (score < 0 || score > 10) {
            printf("Invalid input! The maximum score is 10 and the minimum score is 0. Please try again.\n");
        }
    } while (score < 0 || score > 10); // Continue prompting if the score is invalid

    check_pass(score, passing_percent);

    // Ask if the user wants to take the final chance exam
    printf("Final chance. (0 for yes, any other number for no): ");
    scanf("%i", &removal);
    
    if (removal != 0) {
        printf("You chose not to take the final chance exam.\n");
        return 1;
    }

    // Use a do while loop to repeatedly ask for the score until a valid one is entered
    do {
        printf("Insert your score for the final chance exam: ");
        scanf("%i", &score);

        if (score < 0 || score > 10) {
            printf("Invalid input! The maximum score is 10 and the minimum score is 0. Please try again.\n");
        }
    } while (score < 0 || score > 10); // Continue prompting if the score is invalid

    check_pass(score, passing_percent);
    // 5. end program
    return 0;
}

void exams(){

     for (int i = 0; i < amount_exam; i++) {
        do {
            printf("Insert your score for exam %d: ", i + 1);
            scanf("%i", &score);
            if (score < 0 || score > 10) {
                printf("Invalid input! The maximum score is 10 and the minimum score is 0. Please try again.\n");
            }
        } while (score < 0 || score > 10);

        // Add the score to the total score
        ttl_score += score;
        
        
    }
    printf("Total score: %i\n", ttl_score);

}

void check_pass(int test, int pass_per){
    
    if (test >= pass_per) {
        printf("You passed!\n");
        exit(0); // Exit out of main
    } else {
        printf("You failed.\n");
    }

}