#include <iostream>
using namespace std;

int reverse (int num){
    int ans =0;
    bool isNegative = false;
    if (num < 0)
    {
        isNegative = true;
        num = -num;
    }
    
    while (num!=0)
    {
        int digit = num % 10;
        //if ((ans>INT32_MAX) || (ans<INT32_MIN))
        //{
          //  return 0 ;
      //  }
        ans = ans*10 + digit ;
        num= num/10 ;
    }
    return isNegative ? -ans : ans;
}
 int main (){
    int num;
    cin>> num;
    int result = reverse(num);
    cout<<"reverse of "<<num<<" is "<<result;
    return 0;
 }