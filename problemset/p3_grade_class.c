#include <stdio.h>

// Function prototypes
int getScoreInput();
void classifyGrade(int score);

// Main function
int main() {
    int score;

    // Get validated score input from the user
    score = getScoreInput();

    // Classify the score into a grade
    classifyGrade(score);

    return 0;
}

int getScoreInput() {
    int score;
    char term; // To capture any leftover characters

    while (1) {
        printf("Enter a score (0-100): ");
        if (scanf("%d%c", &score, &term) != 2 || term != '\n' || score < 0 || score > 100) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid integer score between 0 and 100.\n");
        } else {
            // Valid input received
            break;
        }
    }
    return score;
}

void classifyGrade(int score) {
    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }
}