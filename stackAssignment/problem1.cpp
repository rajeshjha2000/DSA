// Problem 1: Count the reversal/ minimum bracket reversal [GFG]

#include <iostream>
#include <stack>
using namespace std;

int countRev (string s)
{
    // If the string size is odd, it's impossible to balance the braces, so return -1
    if(s.size() & 1) return -1;
    
    int ans = 0;           // This will store the number of reversals needed
    stack<char> st;        // Stack to keep track of unmatched braces
    
    // Iterate through each character in the string
    for(char ch : s) {
        if(ch == '{') {
            // If the character is an opening brace, push it onto the stack
            st.push(ch);
        } else {
            // If the character is a closing brace
            if(!st.empty() && st.top() == '{') {
                // If there is a matching opening brace on the top of the stack, pop it
                st.pop();
            } else {
                // If there isn't a matching opening brace, push the closing brace onto the stack
                st.push(ch);
            }
        }
    }
    
    // At this point, the stack contains only unmatched braces
    // We will count the minimum number of reversals required to balance the remaining braces
    while(!st.empty()) {
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        
        // If the two characters are the same, only one reversal is needed
        if(a == b) {
            ans += 1;
        } else {
            // If the two characters are different, two reversals are needed
            ans += 2;
        }
    }
    
    return ans; // Return the total number of reversals needed
}

int main() {
    string s = "{{{{}}";
    cout << "Number of reversals needed: " << countRev(s) << endl;
    return 0;
}
