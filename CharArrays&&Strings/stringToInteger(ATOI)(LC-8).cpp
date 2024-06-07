class Solution {
public:
    int myAtoi(string s) {
        // Initialize variables:
        // num to store the resulting number,
        // i to iterate through the string,
        // sign to keep track of the sign of the number (1 for positive, -1 for negative)
        int num = 0, i = 0, sign = 1;

        // Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') {
            i++; // Increment index to skip any leading spaces
        }

        // Check if the next character is a sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            // If the character is '-', set sign to -1
            // If the character is '+', sign remains 1
            sign = (s[i] == '+') ? 1 : -1;
            i++; // Move to the next character after the sign
        }

        // Process the subsequent characters as long as they are digits
        while (i < s.size() && isdigit(s[i])) {
            // Check for overflow:
            // - If num is greater than INT_MAX / 10, adding another digit would overflow
            // - If num equals INT_MAX / 10, adding a digit greater than 7 would overflow
            // (because INT_MAX is 2147483647 and 214748364 * 10 + 8 is too large)
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > 7)) {
                // Return INT_MAX or INT_MIN depending on the sign if overflow is detected
                return (sign == -1) ? INT_MIN : INT_MAX;
            }

            // Accumulate the digit in num
            // (s[i] - '0') converts the character to its numeric value
            num = num * 10 + (s[i] - '0');

            i++; // Move to the next character
        }

        // Return the final result after applying the sign
        return num * sign;
    }
};
