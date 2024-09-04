/* This is not the most efficient program but it will work for the problem. */
#include <stdio.h>

// Global variables
int amount_exam = 10;
float passing_percent = 5.00;

int main() {
    // Initialize each value
    int score = 0;
    int ttl_score = 0;
    int removal;

    // Get inputs for each exam score
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

    // Print the total score
    printf("Total score: %i\n", ttl_score);

    // Calculate the average score
    float average = (float)ttl_score / amount_exam;

    // Print the average score
    printf("Average score: %.2f\n", average);

    // Check if the average score meets the passing percentage
    if (average >= passing_percent) {
        printf("You passed!\n");
        return 0; // Exit out of main
    } else {
        printf("You failed.\n");
    }

    // Ask if the user wants to take the removal exam
    printf("Would you like to take the removal exam? (0 for yes, any other number for no): ");
    scanf("%i", &removal);
    
    if (removal != 0) {
        printf("You chose not to take the removal exam.\n");
        return 1;
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

    if (score >= passing_percent) {
        printf("You passed the removal exam!\n");
        return 0; // Exit out of main
    } else {
        printf("You failed the removal exam.\n");
    }

    // Ask if the user wants to take the final chance exam
    printf("Final chance. (0 for yes, any other number for no): ");
    scanf("%i", &removal);
    
    if (removal != 0) {
        printf("You chose not to take the final chance exam.\n");
        return 1;
    }

    // Use a do-while loop to repeatedly ask for the score until a valid one is entered
    do {
        printf("Insert your score for the final chance exam: ");
        scanf("%i", &score);

        if (score < 0 || score > 10) {
            printf("Invalid input! The maximum score is 10 and the minimum score is 0. Please try again.\n");
        }
    } while (score < 0 || score > 10); // Continue prompting if the score is invalid

    if (score >= passing_percent) {
        printf("You passed the final chance exam!\n");
    } else {
        printf("You failed the final chance exam.\n");
    }

    return 0;
}
