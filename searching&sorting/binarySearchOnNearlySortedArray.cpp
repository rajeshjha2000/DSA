#include <iostream>
#include <vector>
using namespace std;

// find target in nearly sorted array 
int searchNearlySorted(vector <int> arr, int target){
 int n = arr.size();
 int s = 0;
 int e = n -1 ;
int  mid = s+(e-s)/2;

while (s<=e)
{
    // catch1 => arr[-1] par code fat jayega
    if (mid-1>=0 && arr[mid-1]==target)
    {
        return mid-1;
    }

     if(arr[mid]==target){
        return mid;
     }

  // catch 2 => arr[n] par code fat jayega
    if (mid+1<n && arr[mid+1]==target)
    {
        return mid+1;
    }
     // catch 3 => go to right side 
    
    if (arr[mid]<target)
    {
        s = mid+2;
    } 

    // catch 4 => go to left side

    else{
        e = mid - 2;
    }
    mid = s + (e-s)/2;
}
return -1;

}

int main(){
    vector<int> arr{20,10,30,50,40,70,60};
    int target = 1000;
    
    int index = searchNearlySorted(arr, target);

    if (index == -1)
    {
        cout<<"target not found"<<endl;

    }

    else{
        cout<<"target "<<target<<" found at index "<< index<<endl;
    }
    return 0;
}