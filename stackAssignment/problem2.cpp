// Problem 2 : Remove All Adjacent Duplicate In String [LC-1047]

#include <iostream>
#include <stack>
#include <algorithm> // For the reverse function
using namespace std;

class Solution {
    public:
    string removeDuplicates(string s) {
        stack<char> st; // Stack to keep track of characters
        
        // Iterate through each character in the string
        for(auto ch : s) {
            if (!st.empty() && st.top() == ch) {
                // If the stack is not empty and the top element is the same as the current character
                st.pop(); // Remove the top element (duplicate found)
            } else {
                // If no duplicate, push the current character onto the stack
                st.push(ch);
            }
        }
        
        string ans; // To store the result string without duplicates
        
        // Pop all elements from the stack and add them to the result string
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // The characters are added in reverse order, so reverse the string
        reverse(ans.begin(), ans.end());
        
        return ans; // Return the result string without duplicates
    }
};

int main() {
    Solution sol;
    string s = "abbaca";
    cout << "Result after removing duplicates: " << sol.removeDuplicates(s) << endl;
    return 0;
}
