#include <iostream>
using namespace std;

void shiftNegativeOneSide(int arr[], int n){
 int j =0; 
 // j is a memory block where we can store negative number

 for (int index = 0; index < n; index++)
 {
    //index is a looping variable which will use to traverse the entire array
    if (arr[index] < 0 )
    {
        swap(arr[index], arr[j]);
        j++;
    }
    
 }
 
}

int main(){
    int arr[]={23,-7,12,-10,-11,40,60};
    int n = 7;

    shiftNegativeOneSide(arr,n);

    cout<<"printing the array :"<<endl;

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}