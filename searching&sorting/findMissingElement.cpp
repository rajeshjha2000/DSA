#include <iostream>
using namespace std;


int findMissingElement(int arr[], int n){
      int s = 0;
      int e = n-1;
      int mid = s + ( e - s)/2 ;
      int ans = -1;

      while (s<=e)
      {
        int diff = arr[mid] - mid; 

        // if difference is equal to 1 skip the left part
        if (diff==1)
        {
            s = mid + 1;
        }
        
        // if diffrence is equal to 2 then store the answer and skip the right part
        else if (diff==2)
        {
             ans = mid;
             e = mid - 1;
        }
        
       // important step => update the mid index 
        mid = s + ( e - s)/2 ;

      }

     if (ans+1==0)
     {
        return n+1;
     }
     

      return ans+1;
      
}




int main(){
    int arr[] = {1,2,3,4,6,7,8,9};
    int n = 8;
    
    cout<< findMissingElement(arr,n);
    return 0;
}