#include <iostream>
using namespace std;

void findSumUptoN (int num){
    int sum = 0;
    for (int i = 1; i <=num; i++)
    { 
        sum = sum + i ;
       
    }
     cout<<"sum of numbers : "<<sum;
}

int main(){
   findSumUptoN(10);
   return 0;
}