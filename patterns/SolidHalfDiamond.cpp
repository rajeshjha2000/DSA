#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < 2*n-1; i++)
    {
        int cond = i < n ? i : n -(i%n) - 2;
        for (int j = 0; j <= cond; j++)
        {
            cout<<"*";
        }
      cout<<endl;   
    }
    
}