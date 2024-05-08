#include <iostream>
using namespace std;

int printMaximum (int a, int b, int c){
    int ans1 = max(a,b);
    int final = max(ans1,c);
    return final;
}

int main(){
    int max = printMaximum(10,30,1000);
   cout<< "maximum of 3 number is : "<<max<<endl;
   return 0;
}