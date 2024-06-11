#include <iostream>
using namespace std;

bool checkSorted(int arr[], int size, int index){
    // base case
    if (index>=size){
        return true;
    }
   // processing
   if (arr[index]>arr[index-1])
   {
    // aage check krna padega
    // ab recursion sambhalega
    bool aageKaAnswer = checkSorted(arr, size, index+1);
    return aageKaAnswer;
   }
   else{
    // sorted nhi hai
    return false;
   }
   
    
}

int main(){
    int arr[]={10,20,30,50,60,70};
    int size=6;
    int index=1;

    bool isSorted= checkSorted(arr,size,index);

    if (isSorted)
    {
        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"array is not sorted"<<endl;
    }
}