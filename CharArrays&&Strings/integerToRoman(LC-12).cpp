#include <string>

class Solution {
public:
    string intToRoman(int num) {
        string result = ""; // Initialize an empty string to store the Roman numeral
        
        // Arrays to store the Roman numeral symbols and their corresponding values
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        // Iterate through the symbols and values arrays
        for (int i = 0; i < values.size(); i++) {
            // Repeat adding the current symbol while the num is greater than or equal to its value
            while (num >= values[i]) {
                result += symbols[i]; // Append the current symbol to the result
                num -= values[i]; // Subtract the corresponding value from num
            }
        }
        
        return result; // Return the resulting Roman numeral
    }
};
