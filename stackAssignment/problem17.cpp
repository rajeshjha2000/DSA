// Problem 17: Minimum Add To Make Parentheses Valid[LC-921]

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st; // Stack to keep track of '(' characters
        int ans = 0;    // Counter for the number of insertions needed

        // Iterate over each character in the string
        for (auto ch : s) {
            if (ch == '(') {
                // If the character is '(', increment the counter and push it onto the stack
                ++ans;
                st.push(ch);
            } else {
                // If the character is ')'
                if (!st.empty()) {
                    // If the stack is not empty, pop the top '(' and decrement the counter
                    st.pop();
                    --ans;
                } else {
                    // If the stack is empty, increment the counter
                    ans++;
                }
            }
        }

        return ans; // Return the number of insertions needed
    }
};

