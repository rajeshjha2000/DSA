#include <iostream>
using namespace std;

void printingAnArray(int arr[],int size, int index){
    // base case
    if(index>=size){
        return;
    }
    // processing
    cout<<arr[index]<<" ";

    // recursive call
    printingAnArray(arr,size,index+1);
}

int main(){
    int arr[] = {10,20,30,40,50};
    int size = 5;
    int index=0;
    printingAnArray(arr,size,index);
}