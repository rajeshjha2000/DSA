#include<iostream>
using namespace std;

void solve(int arr[], int size, int index){
    // base case
    if (index>=size)
    {
        return;
    }
    // processing
    arr[index]= 2*arr[index];
    // recursive call
    solve(arr,size,index+1);
    
}

int main(){
    int arr[]={10,11,12,13,14};
    int size=5;
    int index=0;
    solve(arr,size,index);

    // printing vector
    for(int num: arr){
        cout<< num << " ";
    }
}