#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // step 01=> find part from s when part found then erase it from s
        while(s.find(part) != string::npos) {
            // if inside loop, it means that part exists in string
            s.erase(s.find(part), part.length());
        }
        // step 02=> return s
        return s;
    }
};

int main() {
    Solution solution;
    string s = "daabcbaabcbc";  // Example input
    string part = "abc";  // Part to be removed
    string result = solution.removeOccurrences(s, part);
    cout << "Result: " << result << endl;  // Output should be "dab"
    return 0;
}
