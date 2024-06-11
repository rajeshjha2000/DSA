#include <iostream>
using namespace std;

int findInArray(int arr[],int size,int target, int index){
    // base case
    if(index>=size){
        return -1;
    }
    // processing
     if(arr[index]==target){
        return index;
     }

    // recursive call
   findInArray(arr,size,target,index+1);
}

int main(){
    int arr[] = {10,20,30,40,50};
    int size = 5;
    int index=0;
    int target=50;
   cout<< findInArray(arr,size,target,index)<<endl;
}