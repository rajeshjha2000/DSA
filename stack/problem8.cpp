// Problem 8: Valid Parentheses (Leetcode-20)

/*
PROBLEM STATEMENT:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "( () ( () ) )"
Output: true

Example 5:
Input: s = "("
Output: false

Example 6:
Input: s = ")"
Output: false

Time complexity: O(N), where N is size of string
Space complexity: O(N), where N is number of open brackets in stack
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Initialize a stack to keep track of opening brackets
        
        // Iterate through each character in the input string
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i]; // Current character
            
            // If the current character is an opening bracket, push it onto the stack
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else { // The current character is a closing bracket
                // Check if the stack is not empty
                if(!st.empty()) {
                    // Check if the current closing bracket matches the top opening bracket in the stack
                    if((ch == ')' && st.top() == '(') ||
                       (ch == '}' && st.top() == '{') ||
                       (ch == ']' && st.top() == '[')) {
                        st.pop(); // Pop the matching opening bracket from the stack
                    }
                    else { 
                        // No match for the current closing bracket
                        return false;
                    }
                }
                else {
                    // Stack is empty but we encountered a closing bracket, so it's invalid
                    return false;
                }
            }
        }
        
        // If the stack is empty after processing all characters, the string is valid
        return st.size() == 0;
    }
};
