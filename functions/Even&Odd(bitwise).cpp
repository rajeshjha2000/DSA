#include <iostream>
using namespace std;

bool checkEven (int n){
    { 
        if ((n&1)==0)
        {
            return true;
        }
        
        else{
       return false;
    }
     
    }

   
}

int main(){
    int n ;
    cin>>n ;
  bool isEven = checkEven(n);
   
   if (isEven)
   {
    cout<<n<<" is even number";
   }

   else{
    cout<<n<<" is odd number";
    } 
   
   return 0;
}