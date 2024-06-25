// Problem 9: Simplify Path [LC-71]

class Solution {
public:
    // Helper function to build the final simplified path from the stack
    void buildAns(stack<string>& s, string& ans) {
        if (s.empty()) {
            return;
        }
        // Pop elements from stack and append to the answer
        string minPath = s.top(); s.pop();
        buildAns(s, ans);
        ans += minPath;
    }

    // Function to simplify the given Unix-style path
    string simplifyPath(string path) {
        stack<string> s; // Stack to keep track of valid directory names
        int i = 0;

        while (i < path.size()) {
            // Find the start and end of the current directory or file name
            int start = i;
            int end = i + 1;
            while (end < path.size() && path[end] != '/') {
                ++end;
            }

            // Extract the current part of the path
            string minPath = path.substr(start, end - start);
            i = end;

            // Skip over single '/' or '/.'
            if (minPath == "/" || minPath == "/.") {
                continue;
            }

            // If it's not a '/..' (parent directory), push it onto the stack
            if (minPath != "/..") {
                s.push(minPath);
            } else if (!s.empty()) {
                // If it's '/..' (parent directory) and stack is not empty, pop from stack
                s.pop();
            }
        }

        // Initialize the answer as "/" if stack is empty, otherwise as empty string
        string ans = s.empty() ? "/" : "";
        buildAns(s, ans);
        return ans;
    }
};
