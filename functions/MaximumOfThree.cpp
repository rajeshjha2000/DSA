#include <iostream>
using namespace std;

int printMaximum (int a, int b, int c){
    int ans1 = max(a,b);
    int final = max(ans1,c);
    return final;
}

int main(){
    int maximum = printMaximum(10,30,1000);
   cout<< "maximum of 3 number is : "<<maximum<<endl;
   return 0;
}