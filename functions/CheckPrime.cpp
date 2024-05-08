#include <iostream>
using namespace std;

bool checkPrime (int num){
    for (int i = 2; i <=num; i++)
    { 
        if (num%i==0)
        {
            return false;
        }
        
       
    }
     return true;
}

int main(){
  bool prime = checkPrime(10);
   
   if (prime)
   {
    cout<<"its a prime number";
   }

   else{
    cout<<"its not a prime";
    } 
   
   return 0;
}