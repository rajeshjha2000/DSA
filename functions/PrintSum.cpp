#include <iostream> 
using namespace std;

void printSum (int a, int b, int c) {
    int ans = a + b + c ;
    cout<< "sum of the number is :" << ans << endl;
}

int main (){
    printSum(11,13,17);
    return 0;
}