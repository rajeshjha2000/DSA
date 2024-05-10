#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int target){

    for (int i = 0; i < size; i++)
    {
        if (arr[i]==target)
        {
          return true;
        }
        
    }
    return false;
}


int main (){
  int arr[]= {10,20,30,40,50};
   int size = 5;
   int target = 30;

   bool ans = LinearSearch(arr, size, target) ;

  if (ans==1)
  {
    cout<<"target found"<<endl;

  }
  else{
    cout<<"not found";
  }
  return 0;
}