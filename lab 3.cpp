#include <iostream>
using namespace std;

void generateMagicSquare(int magicSquare[5][5]) {
    int n = 5; 
    int r = 0;
    int c = 2;
    // this loop is for initializing the array to 0 but their is a better way to do this
    // you can use memset(magicSquare, 0, sizeof(magicSquare));
    // -memset is a function that is used to fill a block of memory with a particular value
    for (int i = 0; i < n; i++){ // N BEING THE SIZE OF THE SQUARE
        for (int j = 0; j < n; j++) { 
            magicSquare[i][j] = 0;


        }
    }
    
    // this is the first number that is going to be placed in the magic square
    magicSquare[r][c] = 1; 
    // 1 starting value
    
    for (int i = 2; i <= 25; i++) { // 25 is the size of the magic square
        r--; 
        c++; 
        
        if (r < 0 && c >= n) {
            r += 2; 
            c--; 
        } else if (c >= n) { 
            c -= n; 
        } else if (r < 0) {
            r += n; 
        } else if (magicSquare[r][c] != 0) { 
            r += 2; 
            c--;  
        }

        magicSquare[r][c] = i;
    }
}


void printMagicSquare(int magicSquare[5][5]) {
    int n = 5; // n is the size of the magic square
    cout << "Magic Square of size 5x5:\n";
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            
            if (magicSquare[r][c] < 10) {
                cout << "  " << magicSquare[r][c] << " "; 
            } else {
                cout << " " << magicSquare[r][c] << " "; 
            }
        }
        cout << endl;
    }
}

int main() {
    int magicSquare[5][5]; 

    generateMagicSquare(magicSquare); 
    printMagicSquare(magicSquare); 

        return 0;
}

