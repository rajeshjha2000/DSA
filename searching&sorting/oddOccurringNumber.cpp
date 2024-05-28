#include <iostream>
#include <vector>
using namespace std;

int findOddOccuringElement(vector<int> arr){
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    
    while (s<=e)
    {
        // single element 
        if (s == e)
        {
            return s;
        }
        
        // when mid is odd
        if (mid & 1)
        {
            // go to right side.. catch => mid-1>=0 because arr[-1] is not possible
            if (mid-1>=0 && arr[mid]==arr[mid-1])
            {
                s = mid + 1 ;
            }
            // go to left side 
            else{
                e = mid - 1;
            }
        }
        
         // when mid index is even

         else{

            // go to the right side to get the answer... catch => mid+1<n
            if (mid+1<n && arr[mid]==arr[mid+1])
            {
                // catch => we dont want to compare single elment twice
                s = mid + 2;
            }
           
          
            else{
                // ya to mai right part par khada hu
          // ya to mai answer par khada hu
          // thats why e = mid,  bcoz e = mid - 1 se answer lost ho skta hai
               ans=mid;
               e=mid;
            }
            
         }
         // update mid
         mid = s + (e-s)/2 ;
    }
    return ans;
}

int main(){
    vector <int> arr{10,10,2,2,5,5,2,5,5,20,20,11,11,10,10};
    int ansIndex = findOddOccuringElement(arr);
    
    if (ansIndex==-1)
    {
        cout<<ansIndex<<endl;
    }
    else{
        cout<<"final ans is : "<<arr[ansIndex]<<endl;
    }

    return 0;
}