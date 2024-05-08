#include <iostream>
using namespace std;

void findSumUptoN (int num){
    int sum = 0;
    for (int i = 2; i <=num; i=i+2)
    { 
        sum = sum + i ;
       
    }
     cout<<"sum of numbers : "<<sum;
}

int main(){
   findSumUptoN(11);
   return 0;
}