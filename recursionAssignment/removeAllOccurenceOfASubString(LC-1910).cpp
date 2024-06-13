#include<iostream>
#include<string> // Corrected header file
using namespace std;

class Solution {
    public:
    // Function to remove all occurrences of 'part' from 's'
    void removeOCCRE(string &s, string &part) {
        int found = s.find(part);
        if (found != string::npos) {
            // part string has been located, remove it
            string left_part = s.substr(0, found);
            string right_part = s.substr(found + part.size(), s.size());
            s = left_part + right_part;
            // Recursive call to remove all occurrences
            removeOCCRE(s, part);
        } else {
            // Base case: all occurrences have been removed from 's'
            return;
        }
    }

    // Wrapper function to call the recursive function
    string removeoccurrence(string s, string part) {
        removeOCCRE(s, part);
        return s;
    }
};

int main() {
    Solution sol;
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = sol.removeoccurrence(s, part);
    cout << result << endl; // Output should be "dab"
    return 0;
}

// T.C. -> O(NM) + O(N) + O (N) = O(NM)