#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // If numRows is 1 or less, return the original string
        if (numRows <= 1) return s;

        vector<string> rows(min(numRows, int(s.size()))); // Create a vector of strings to represent each row
        int currentRow = 0; // Initialize the current row index
        bool goingDown = false; // Variable to track the direction of traversal

        // Iterate through each character in the string
        for (char c : s) {
            rows[currentRow] += c; // Append the current character to the current row
            if (currentRow == 0 || currentRow == numRows - 1) // If at the top or bottom row, change direction
                goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1; // Move to the next or previous row based on direction
        }

        string result; // Initialize the result string

        // Concatenate all rows to form the final result
        for (string row : rows) {
            result += row;
        }

        return result; // Return the final result string
    }
};
