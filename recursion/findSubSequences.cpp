#include<iostream>
#include<string.h>
using namespace std;

void findSubSequence(string str, string output, int index){
    // base case
    if (index>=str.length())
    {
        // ans jo h, wo output string me build ho chuka hai
        // print kr do
        cout<<"->"<<output<<endl;
        return;
    }

    char ch = str[index];

    //exclude
    findSubSequence(str,output,index+1);

    //include
    // output string me ch character ko include kro
    output.push_back(ch);
    findSubSequence(str,output,index+1);

    
}

int main(){
    string str= "abc";
    string output = "";
    int index = 0;
    findSubSequence(str,output,index);

}