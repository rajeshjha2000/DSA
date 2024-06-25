// Problem 16: Remove K Digits[LC-402]

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> st; // Stack to keep track of digits in the result

        // Iterate over each digit in the input number
        for (auto digit : num) {
            // If we still need to remove digits (k > 0)
            if (k > 0) {
                // Remove digits from the stack if the current digit is smaller
                // and we still need to remove digits (k > 0)
                while (!st.empty() && st.top() > digit) {
                    st.pop();
                    k--;
                    if (k == 0) break; // Stop if no more digits need to be removed
                }
            }
            st.push(digit); // Push the current digit onto the stack
        }

        // If we still need to remove digits after processing all digits
        if (k > 0) {
            while (!st.empty() && k > 0) {
                st.pop();
                k--;
            }
        }

        // Build the result string from the stack
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Remove leading zeros from the result string
        while (ans.size() > 0 && ans.back() == '0') {
            ans.pop_back();
        }

        // Reverse the result string to get the correct order
        reverse(ans.begin(), ans.end());

        // Return "0" if the result is empty, otherwise return the result
        return ans == "" ? "0" : ans;
    }
};
