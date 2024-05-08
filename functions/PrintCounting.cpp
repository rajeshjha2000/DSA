#include <iostream>
using namespace std;

void printCounting (int num){
    for (int i = 1; i <=num; i++)
    {
        cout<<i<<endl;
    }
    
}

int main(){
   printCounting(100);
   return 0;
}