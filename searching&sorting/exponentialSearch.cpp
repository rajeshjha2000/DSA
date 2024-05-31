#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr,int start, int end, int target ){
    int mid = start + (end - start)/2 ;
    while (start<=end)
    {
        if (arr[mid]==target)
        {
            return mid;
        }
        else if (arr[mid]<target)
        {
            start = mid + 1;
        }
        
        else{
            end = mid - 1;
        }
         int mid = start + (end - start)/2;
    }
    return -1;
}

int exponentialSearch(vector<int>& arr, int x){
    int n = arr.size();

    if (arr[0]==x)
    {
        return 0;
    }
    
    int i = 1;
    while (i<n && arr[i]<=x)
    {
        i = i*2;
    }
    return binarySearch(arr, i/2, min(i, n-1), x) ;
}
int main(){
    vector <int> arr{3,4,5,6,11,13,14,15,56,70};
    int target = 13 ;

    int ans = exponentialSearch(arr, target);

    cout<<"element"<<target<<"found at the index :"<<ans << endl ;
    return 0;
}