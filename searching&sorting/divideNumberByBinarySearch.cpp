#include <iostream>
using namespace std;

// divide two numbers using binary search
int getQuotient (int dividend, int divisor){
    int s=0;
    int e = dividend;
    int mid = s + (e-s)/2 ;
    int ans = -1;

    while (s<=e)
    {
        // return quotient 
        if (mid * divisor == dividend)
        {
            return mid;
        }
        // go toleft side to get the possible quoteint

        else if (mid * divisor > dividend)
        {
            e = mid - 1;
        }
        
        else if (mid * divisor < dividend)
        {
            ans = mid;
            s = mid + 1;
        }
        
       // update mid
       mid = s + (e -s)/2;
        
    } 
    return ans;
    
}

int main(){
    int dividend = 29;
    int divisor = -7;
    int quotient = getQuotient(abs(dividend), abs(divisor));

    // now we need to decide ki sign konsa lagaye +ve ya -ve

    if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0)){
        quotient= 0 -quotient;
    }
    
    cout<<"quotient: "<<quotient<<endl;
    
}