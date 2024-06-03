#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        // step 01=> create a temp variable
        string temp = "";
        int n = s.length();
        int index  = 0;

        while(index < n){
            // step 02 => compare input string element with rightmost element of temp string
            // when both elements are the same, pop element from temp
            if(temp.length() > 0 && s[index] == temp[temp.length() - 1]){
                temp.pop_back();
            }
            // when both elements are different, push element in temp
            else{
                temp.push_back(s[index]);
            }
            index++;
        }
        return temp;
    }
};

int main() {
    Solution solution;
    string s = "abbaca";  // Example input
    string result = solution.removeDuplicates(s);
    cout << "Result: " << result << endl;  // Output should be "ca"
    return 0;
}
