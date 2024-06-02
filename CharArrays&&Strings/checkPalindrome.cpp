#include <iostream>
#include <cstring>
using namespace std;

int findLength(char ch[], int maxSize){
    int length = 0;
    while (ch[length] != '\0' && length < maxSize){
        length++;
    }
    return length;
}

bool checkPalindrome(char ch[], int n){
    int i = 0;
    int j = n - 1;

    while (i <=j){
        if (ch[i] == ch[j]){
            i++;
            j--;
        } else {
            // characters are not matching
            return false;
        }
    }
    return true;
}

int main(){
    char ch[100];

    cin.getline(ch, 100);

    int len = findLength(ch, 100); 

    bool isPalindrome = checkPalindrome(ch, len);

    if (isPalindrome){
        cout << "valid palindrome" << endl;
    } else {
        cout << "not valid palindrome" << endl;
    }

    return 0;
}
