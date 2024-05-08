#include <iostream>
using namespace std;

int reverse (int n){
    int ans =0;
    bool isNegative = false;
    if (n < 0)
    {
        isNegative = true;
        n = -n;
    }
    
    while (n!=0)
    {
        int digit = n % 10;
        //if ((ans>INT32_MAX) || (ans<INT32_MIN))
        //{
          //  return 0 ;
      //  }
        ans = ans*10 + digit ;
        n = n/10 ;
    }
    return isNegative ? -ans : ans;
}
 int main (){
    int n;
    cin>> n;
    int result = reverse(n);
    cout<<"reverse of "<<n<<" is "<<result;
    return 0;
 }