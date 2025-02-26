#include <iostream>
#include <cstring> // For memset

const int MATRIX_COLUMN = 5;
const int MATRIX_ROW = 5;

int main(int argc, char **argv) {
    int matrix[MATRIX_ROW][MATRIX_COLUMN];

    // Initialize matrix with zeros
    memset(matrix, 0, sizeof(matrix));
    
    // Print empty matrix (optional)
    for (int row = 0; row < MATRIX_ROW; row++) {
        for (int column = 0; column < MATRIX_COLUMN; column++) {
            std::cout << matrix[row][column] << " ";
        }
        std::cout << "\n";
    }

    // Starting position
    int counter = 1;
    int mRow = 0, mCol = MATRIX_COLUMN / 2;
    
    // Fill the magic square using Siamese method
    while (counter <= MATRIX_ROW * MATRIX_COLUMN) {
        matrix[mRow][mCol] = counter++;
        
        // Store current position before moving
        int prevRow = mRow;
        int prevCol = mCol;
        
        // Move diagonally up-right (with wrapping)
        mRow = (mRow - 1 + MATRIX_ROW) % MATRIX_ROW;    // Move up with wrapping
        mCol = (mCol + 1) % MATRIX_COLUMN;             // Move right with wrapping
        
        // If the cell is already filled, go below the previous position
        if (matrix[mRow][mCol] != 0) {
            mRow = (prevRow + 1) % MATRIX_ROW;
            mCol = prevCol;
        }
    }
    
    // Print the completed magic square
    std::cout << "\nMagic Square:\n";
    for (int row = 0; row < MATRIX_ROW; row++) {
        for (int column = 0; column < MATRIX_COLUMN; column++) {
            std::cout << matrix[row][column] << "\t";
        }
        std::cout << "\n";
    }
    
    // Verify it's a magic square by checking the magic constant
    int magicConstant = MATRIX_ROW * (MATRIX_ROW * MATRIX_ROW + 1) / 2;
    std::cout << "\nMagic Constant should be: " << magicConstant << "\n";
    
    // Check sum of rows
    std::cout << "Row sums: ";
    for (int row = 0; row < MATRIX_ROW; row++) {
        int sum = 0;
        for (int column = 0; column < MATRIX_COLUMN; column++) {
            sum += matrix[row][column];
        }
        std::cout << sum << " ";
    }
    
    // Check sum of columns
    std::cout << "\nColumn sums: ";
    for (int column = 0; column < MATRIX_COLUMN; column++) {
        int sum = 0;
        for (int row = 0; row < MATRIX_ROW; row++) {
            sum += matrix[row][column];
        }
        std::cout << sum << " ";
    }
    
    // Check sum of diagonals
    int diagSum1 = 0, diagSum2 = 0;
    for (int i = 0; i < MATRIX_ROW; i++) {
        diagSum1 += matrix[i][i];
        diagSum2 += matrix[i][MATRIX_COLUMN - 1 - i];
    }
    std::cout << "\nDiagonal sums: " << diagSum1 << " " << diagSum2 << "\n";
    
    return 0;
}