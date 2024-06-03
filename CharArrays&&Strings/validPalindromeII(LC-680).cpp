#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Palindrome function
    bool checkPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }
   
    bool validPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int end = n - 1;

        while (start < end) {
            // Step 01=>
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                // Only one removal allowed
                // Check palindrome for remaining string after removal

                // s[start] character removal
                bool ans1 = checkPalindrome(s, start + 1, end);

                // s[end] character removal
                bool ans2 = checkPalindrome(s, start, end - 1);

                // Step 03
                return ans1 || ans2;
            }
        }
        // If reached here, it means the string is a valid palindrome
        // This means zero removals are needed
        return true;
    }
};

int main() {
    Solution solution;
    string test1 = "abca";
    cout << "Is \"" << test1 << "\" a valid palindrome after at most one removal? " 
         << (solution.validPalindrome(test1) ? "Yes" : "No") << endl;

    string test2 = "racecar";
    cout << "Is \"" << test2 << "\" a valid palindrome after at most one removal? " 
         << (solution.validPalindrome(test2) ? "Yes" : "No") << endl;

    return 0;
}
