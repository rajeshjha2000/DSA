#include <iostream>
using namespace std;

void printingAnArray(int arr[],int size, int index){
    // base case
    if(index>=size){
        return;
    }

    // recursive call
    printingAnArray(arr,size,index+1);

       // processing
    cout<<arr[index]<<" ";
}

int main(){
    int arr[] = {10,20,30,40,50};
    int size = 5;
    int index=0;
    printingAnArray(arr,size,index);
}