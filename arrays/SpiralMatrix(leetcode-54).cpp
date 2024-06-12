#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; // Vector to store the result
        int m = matrix.size(); // Number of rows in the matrix
        int n = matrix[0].size(); // Number of columns in the matrix

        int totalElements = m * n; // Total number of elements in the matrix

        // Initialize boundary variables for the spiral traversal
        int startingRow = 0;
        int endingCol = n - 1;
        int endingRow = m - 1;
        int startingCol = 0;

        int count = 0; // Counter to track the number of elements added to the result

        // Traverse the matrix in a spiral order until all elements are processed
        while (count < totalElements) {
            // Printing the starting row
            for (int i = startingCol; i <= endingCol && count < totalElements; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++; // Move the starting row down

            // Printing the ending column
            for (int i = startingRow; i <= endingRow && count < totalElements; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--; // Move the ending column to the left

            // Printing the ending row
            for (int i = endingCol; i >= startingCol && count < totalElements; i++) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--; // Move the ending row up

            // Printing the starting column
            for (int i = endingRow; i >= startingRow && count < totalElements; i++) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++; // Move the starting column to the right
        }

        return ans; // Return the spiral order traversal result
    }
};
