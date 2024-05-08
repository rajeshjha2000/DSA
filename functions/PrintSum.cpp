#include <iostream> 
using namespace std;

void printSum (int a, int b, int c) {
    int answer = a + b + c ;
    cout<< "sum of the number is :" << answer << endl;
}

int main (){
    printSum(1,3,7);
    return 0;
}