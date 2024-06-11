#include <iostream>
using namespace std;

int binSearch (int arr[], int s, int e, int target){
  // base case
   if (s>e)
   {
    // element not found
    return -1;
   }
   
   // processing -> ek case khud solve kro
    int mid = s + (e-s)/2;

    if (arr[mid]==target)
    {
        return mid;
    }
    // baaki recursion dekhega ab
    if (arr[mid]<target)
    {
        // right me jao
        return binSearch(arr,mid+1,e,target);
    }
    
    else{
        // left me jao
        return binSearch(arr,s,mid-1,target);
    }
    
}

int main(){
    int arr[]={10,20,30,40,50,60,70,80};
    int size=8;
    int start=0;
    int end = size - 1;
    int target = 80;

    int foundIndex = binSearch(arr,start,end,target);

    if (foundIndex!= -1)
    {
        cout<<"target found at : "<<foundIndex<<endl;
    }
    
}