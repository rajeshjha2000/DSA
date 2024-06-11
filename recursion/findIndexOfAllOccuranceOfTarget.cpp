#include <iostream>
using namespace std;

void find(int arr[],int size,int target, int index){
    // base case
    if(index>=size){
        return ;
    }
    // processing
     if(arr[index]==target){
        cout<< index<<" ";
     }

    // recursive call
   find(arr,size,target,index+1);
}

int main(){
    int arr[] = {10,20,10,10,40,50};
    int size = 6;
    int index=0;
    int target=10;
   find(arr,size,target,index);
}