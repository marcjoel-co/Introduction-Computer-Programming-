#include <stdio.h>
#include <string.h>
#include "letters_ascii7h.h"


void print_ascii_string(const char *str);

int main(int argc, char *argv[]) {

    if (argc < 2)
    {
        print_ascii_string("MJD");
        return 0;
    }

    for (int i = 1; i < argc; i++) { // NF: start at 1 because argv[0] is literally ./filename
        print_ascii_string(argv[i]);
    }
    return 0;

    
}
// Function to map character to index in the ascii_art array

// Function to print ASCII art for a string of characters
void print_ascii_string(const char* str) {
    // Iterate over each row (i.e., HEIGHT rows)
    for (int row = 0; row < HEIGHT; row++) {
        // Print the row for each character in the string
        for (int i = 0; str[i] != '\0'; i++) {
            int index = char_to_index(str[i]);
            if (index != -1) {
                printf("%s  ", ascii_art[index][row]);  // Print character's row with space
            } else {
                printf("     ");  // If character not found, print empty space (5 spaces)
            }
        }
        printf("\n");  // Move to the next row after printing the row for all characters
    }
}

