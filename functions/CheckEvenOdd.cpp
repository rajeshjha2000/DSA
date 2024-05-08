#include <iostream>
using namespace std;

void printCounting (int n){
   if (n%2==0)
   {
    cout<<"even number";
   }
   else{
    cout<<"odd number";
   }
   
    
}

int main(){
   printCounting(15);
   return 0;
}