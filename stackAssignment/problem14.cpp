// Problem 14: Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // Stack to store indices of characters
        st.push(-1); // Initialize stack with -1 to handle base for valid substrings
        int maxLen = 0; // Variable to store the maximum length of valid parentheses

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // If the character is '(', push its index onto the stack
            if (ch == '(') {
                st.push(i);
            } 
            else {
                // If the character is ')', pop the top of the stack
                st.pop();
                
                // If the stack is empty after popping, push the current index onto the stack
                if (st.empty()) {
                    st.push(i);
                } 
                else {
                    // Calculate the length of the current valid substring
                    int len = i - st.top();
                    // Update maxLen with the maximum length found so far
                    maxLen = max(len, maxLen);
                }
            }
        }
        
        return maxLen; // Return the maximum length of valid parentheses
    }
};
