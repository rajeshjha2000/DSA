#include <iostream>
using namespace std;

void  moveAllNegToLeft( int *arr, int n){
    // dutch national flah algo 
    int l =0;
    int h= n-1;

    while (l<h)
    {
        if (arr[l]<0)
        {
            l++;
        }

        else if (arr[h]>0)
        {
            h--;
        }

        else{
            swap(arr[l],arr[h]);
        }
        
        
    }
    
}

int main(){
    int arr[] = {1,2,-3,4,-5,6};
    int n = sizeof(arr)/sizeof(int);

    moveAllNegToLeft (arr, n);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    

    return 0;
}