#include <iostream>
using namespace std;

int main (){
    int num;
    cin>> num;
 int  n = num/2 ;
 for (int row=0; row<n; row++){
    // inverted half pyramid 1
    for (int col = 0; col < n-row; col++)
    {
        cout<<"*";
    }
    // full pyramid1
    for (int col= 0; col < 2*row+1; col++)
    {
        cout<<" ";
    }
    //inverted half pyramid 2
   for (int col = 0; col < n-row; col++)
   {
    cout<<"*";
   }
   
    cout<<endl;
 }

 for (int row=0; row<n; row++){
    //  half pyramid 1
    for (int col = 0; col < row+1; col++)
    {
        cout<<"*";
    }
    // full pyramid1
    for (int col= 0; col < 2*n-2*row-1; col++)
    {
        cout<<" ";
    }
    // half pyramid 2
   for (int col = 0; col < row+1; col++)
   {
    cout<<"*";
   }
   
    cout<<endl;
 }
}