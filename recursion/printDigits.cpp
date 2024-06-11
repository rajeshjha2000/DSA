#include<iostream>
using namespace std;

void printDigits(int num){
 // base case
 if(num==0){
    return;
 }
 // processing
 int digit = num % 10;

 // recursive call
 printDigits(num/10);
 //processing
 cout << digit << " ";
}

int main(){
    int num = 4217;
    printDigits(num);
}