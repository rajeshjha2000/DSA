#include <iostream>
using namespace std;


int findFirstOccurence(int arr[], int n, int target){
      int s = 0;
      int e = n-1;
      int mid = ( s + e)/2 ;
      int ans = -1;

      while (s<=e)
      {
        if (arr[mid]==target)
        {
            // ans store
            ans = mid;

            // move left
            e = mid -1; 
        }
        
        else if (target > arr[mid])
        {
            // move right 
             s = mid + 1;
        }
        
        else if (target < arr[mid])
        {
            // move left 
            e = mid -1;
        }
        
        // important step
        mid = (s + e)/2 ;

      }
      return ans;
      
}




int main(){
    int arr[] = {10,20,30,30,30,70,80,90};
    int n = 8;
    int target = 30;
    int ansIndex = findFirstOccurence(arr, n, target);

    if (ansIndex==-1)
    {
        cout<<"element not found"<<endl;
    }

    else{
        cout<<"element found at index: "<< ansIndex << endl;
    }
    
    return 0;
}