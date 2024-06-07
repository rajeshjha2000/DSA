class Solution {
public:
    int compress(vector<char>& s) {
        int index = 0, count = 1; // Initialize variables for index and count
        char prev = s[0]; // Initialize prev to the first character of the vector

        for (int i = 1; i < s.size(); i++) { // Iterate through the vector
            if (s[i] == prev) { // If the current character is equal to prev
                count++; // Increment the count of the character
            } else { // If the current character is different from prev
                s[index++] = prev; // Store prev character at current index
                if (count > 1) { // If the count of prev character is greater than 1
                    int start = index; // Store the start index for reversing the count
                    while (count) { // Loop until count becomes 0
                        s[index++] = (count % 10) + '0'; // Store each digit of count as a character
                        count /= 10; // Divide count by 10 to get the next digit
                    }
                    reverse(s.begin() + start, s.begin() + index); // Reverse the count characters
                }
                prev = s[i]; // Update prev to the current character
                count = 1; // Reset count for the new character
            }
        }

        s[index++] = prev; // Store the last character of the vector
        if (count > 1) { // If the count of the last character is greater than 1
            int start = index; // Store the start index for reversing the count
            while (count) { // Loop until count becomes 0
                s[index++] = (count % 10) + '0'; // Store each digit of count as a character
                count /= 10; // Divide count by 10 to get the next digit
            }
            reverse(s.begin() + start, s.begin() + index); // Reverse the count characters
        }

        return index; // Return the new length of the compressed vector
    }
};
