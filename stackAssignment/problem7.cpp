// Problem 7 : check if word is valid after susbtitution[LC-1003]

class Solution {
public:
    bool isValid(string s) {
        // If the string doesn't start with 'a', it can't be valid
        if(s[0] != 'a') return false;

        stack<char> st; // Stack to keep track of 'a' and 'b'

        // Traverse each character in the string
        for(char ch : s) {
            if(ch == 'a') {
                // Push 'a' onto the stack
                st.push(ch);
            }
            else if(ch == 'b') {
                // 'b' should follow 'a'
                if(!st.empty() && st.top() == 'a') {
                    st.push('b');
                } else {
                    return false; // Invalid if 'b' is not preceded by 'a'
                }
            }
            else { // ch == 'c'
                // 'c' should follow 'b' which should follow 'a'
                if(!st.empty() && st.top() == 'b') {
                    st.pop(); // Pop 'b'
                    if(!st.empty() && st.top() == 'a') {
                        st.pop(); // Pop 'a'
                    } else {
                        return false; // Invalid if 'a' doesn't precede 'b'
                    }
                } else {
                    return false; // Invalid if 'c' is not preceded by 'b'
                }
            }
        }

        // The stack should be empty if all "abc" sequences are valid
        return st.empty();
    }
};
