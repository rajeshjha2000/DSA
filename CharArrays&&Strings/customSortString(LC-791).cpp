#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static string orderStr;
    
    // Step 02: In custom comparator, find character position of s string in string order
    static bool compare(char ch1, char ch2) {
        int a = orderStr.find(ch1);
        int b = orderStr.find(ch2);
        
        // Compare between both a & b position to arrange character in string s
        // if a > b -- b comes before a
        // if a < b -- a comes before b
        return a < b;
    }
    
    string customSortString(string order, string s) {
        orderStr = order;

        // Step 01: Use custom comparator to arrange character of string s according to string order
        sort(s.begin(), s.end(), compare);

        // Step 03: Return arranged string s
        return s;
    }
};

// Define the static member variable
string Solution::orderStr;

int main() {
    Solution solution;

    string order1 = "cba";
    string s1 = "abcd";
    cout << "Example 1: " << solution.customSortString(order1, s1) << endl;  // Output: "cbad"
    
    string order2 = "exv";
    string s2 = "xwvee";
    cout << "Example 2: " << solution.customSortString(order2, s2) << endl;  // Output: "eexvw"

    return 0;
}
