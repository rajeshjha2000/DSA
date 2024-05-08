#include <iostream>
using namespace std;

bool checkEven (int num){
    { 
        if ((num&1)==0)
        {
            return true;
        }
        
        else{
       return false;
    }
     
    }

   
}

int main(){
    int num ;
    cin>>num ;
  bool isEven = checkEven(num);
   
   if (isEven)
   {
    cout<<num<<" is even number";
   }

   else{
    cout<<num<<" is odd number";
    } 
   
   return 0;
}