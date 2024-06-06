#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        // Step 01: Create mapping for key
        char start = 'a'; // Start mapping from 'a'
        char mapping[256] = {0}; // Array to store mappings

        for (int i = 0; i < key.size(); i++) {
            char ch = key[i];
            if (ch != ' ' && mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        // Step 02: Use mapping to decode the message
        string ans;
        for (int i = 0; i < message.size(); i++) {
            char ch = message[i];
            if (ch == ' ') {
                ans.push_back(' ');
            } else {
                char decodeChar = mapping[ch];
                ans.push_back(decodeChar);
            }
        }

        // Step 03: Return decoded message
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    
    // Decode the message using the key
    string decodedMessage = solution.decodeMessage(key, message);
    
    // Print the decoded message
    cout << "Decoded message: " << decodedMessage << endl;
    
    return 0;
}
