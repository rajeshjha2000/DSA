#include <iostream>
using namespace std;

void ShiftArray(int arr[], int n){
    //step 1
    int temp = arr[n-1];

    //step 2
    // arr[i] = arr[i-1]

    for (int i = n-1; i >= 1; i--)
    {
        arr[i] = arr[i-1];
    } 

    // copy temp variable to zeroth index of arr
    arr[0]= temp;
    
}
int main(){
   int arr[]={10,20,30,40,50,60};
   int n = 6;

   ShiftArray(arr,n);

   for (int i = 0; i < n; i++)
   {
    cout<<arr[i]<<" ";
   }
   
}