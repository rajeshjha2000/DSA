// Problem 15: Daily Temperature[LC-739]

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); // Initialize the answer vector with 0s
        stack<int> st; // Stack to store indices of temperatures

        // Traverse the temperatures vector
        for (int i = 0; i < temperatures.size(); ++i) {
            // While the stack is not empty and the current temperature is greater than the temperature at the index stored at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                // Calculate the number of days until a warmer temperature
                ans[st.top()] = i - st.top();
                // Pop the index from the stack
                st.pop();
            }
            // Push the current index onto the stack
            st.push(i);
        }

        return ans; // Return the result vector
    }
};


