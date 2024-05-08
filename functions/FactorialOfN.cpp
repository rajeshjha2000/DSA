#include <iostream>
using namespace std;

long long int factorial (long long N){
    long long int fact = 1;
    for (int i = 1; i <=N; i++)
    {
        fact = fact * i ; 
         ;
    }
    return fact;
}

int main (){
    int N;
    cin>>N;
   long long int result = factorial(N);
    cout<<"factorial of "<<N<<" is "<<result;

    return 0;
}