#include <iostream>
#include<strings.h>
using namespace std;

void printPermutation(string &str, int index){
   // base case
   if (index >=str.length()){
       cout<< str << " ";
        return;
   }
  
  for (int j = index; j < str.length() ; j++)
  {
    // 1 case
    swap(str[index], str[j]);

    // recursive call
    printPermutation(str, index+1);

    // backtracking ->
    // isme hum by reference le rhe hain "str" to wo change ho jaayegi backtracking ke time pe to usi ko nullify krne ke liye add kiya hai below statement 
    swap(str[index], str[j]);
  }
  
}

int main(){
    string str = "abc";
    int index= 0;
    printPermutation(str,index);
}