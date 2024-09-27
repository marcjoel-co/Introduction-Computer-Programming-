#include <stdio.h>
#include <string.h>
#include "letters_ascii5h.h"


void print_ascii_char(char c);

// main function to print ASCII art for each character in command-line arguments
int main(int argc, char *argv[]) {
    // Iterate through each argument (starting from index 1) and print each character separately

    if (argc < 2){
        char *facto = "MJD";
        for (int i = 1; i < 3; i++)
        {
        print_ascii_char(facto[i]);
        }
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            print_ascii_char(argv[i][j]);  // Print ASCII art for each character
            printf("\n");  // Separate each character's ASCII art with a newline
        }
    }
    return 0;
    
}

// Function to print ASCII art for a single character
void print_ascii_char(char c) {
    int index = char_to_index(c);  // Get the index for the character
    if (index == -1) {
        printf("Character not supported\n");
        return;
    }
    
    // Print each row of the character's ASCII art
    for (int row = 0; row < HEIGHT; row++) {
        printf("%s\n", ascii_art[index][row]);  // Print each row of the character
    }
}

