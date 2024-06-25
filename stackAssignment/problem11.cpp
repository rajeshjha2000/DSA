// Problem 11: Asteroid Collision [LC-735]

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // Stack to keep track of asteroids

        // Iterate through each asteroid in the given vector
        for (auto ast : asteroids) {
            bool destroy = false; // Flag to check if the current asteroid is destroyed
            
            if (ast > 0) {
                // If the asteroid is moving to the right, simply push it onto the stack
                st.push(ast);
            } else {
                // If the asteroid is moving to the left
                // Check if there is no collision or if the top asteroid in the stack is also moving to the left
                if (st.empty() || st.top() < 0) {
                    st.push(ast); // Push the current asteroid onto the stack
                } else {
                    // There is a collision scenario
                    while (!st.empty() && st.top() > 0) {
                        // If the current asteroid (moving left) has the same size as the top asteroid (moving right)
                        if (abs(ast) == st.top()) {
                            destroy = true; // Both asteroids destroy each other
                            st.pop(); // Remove the top asteroid from the stack
                            break; // Break out of the loop as the current asteroid is also destroyed
                        } else if (abs(ast) > st.top()) {
                            // If the current asteroid (moving left) is larger
                            st.pop(); // Remove the smaller asteroid (moving right)
                            // Continue to check if the current asteroid will hit another asteroid
                        } else {
                            // If the current asteroid (moving left) is smaller
                            destroy = true; // The current asteroid is destroyed
                            break; // Break out of the loop
                        }
                    }
                    // If the current asteroid was not destroyed in the collision, push it onto the stack
                    if (!destroy) {
                        st.push(ast);
                    }
                }
            }
        }

        // Create a vector to store the result in the correct order
        vector<int> ans(st.size());
        // Fill the result vector with elements from the stack
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans; // Return the result
    }
};
