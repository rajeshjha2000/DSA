#include <iostream>
#include <vector>
using namespace std;

void printWaveMatrix(vector<vector<int>> matrix) {
    // Determine the number of rows in the matrix
    int row = matrix.size();
    
    // Determine the number of columns in the matrix
    int col = matrix[0].size();
    
    // Iterate through each column of the matrix
    for (int startCol = 0; startCol < col; startCol++) {
        // Check if the current column index is even
        if ((startCol & 1) == 0) {
            // Iterate through each row from top to bottom
            for (int i = 0; i < row; i++) {
                // Print the element at the current row and column
                cout << matrix[i][startCol] << " ";
            }
        } else {
            // If the current column index is odd, iterate through each row from bottom to top
            for (int i = row - 1; i >= 0; i--) {
                // Print the element at the current row and column
                cout << matrix[i][startCol] << " ";
            }
        }
    }
}

int main() {
    // Define a 2D vector (matrix) to test the function
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Call the function to print the matrix in a wave-like manner
    printWaveMatrix(matrix);
    
    // Return 0 to indicate successful execution
    return 0;
}
