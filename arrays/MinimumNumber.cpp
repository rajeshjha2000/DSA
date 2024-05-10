#include <iostream>
#include <limits.h>
using namespace std;

int findMinInArray(int arr[],int size){
  int minAns = INT_MAX;

  for (int i = 0; i < size; i++)
  {
    if (arr[i]<minAns)
    {
        minAns=arr[i];
    }
    
  }
  return minAns;
}

int main(){
    int arr[] = {10,15,1,13,59,87,44} ;
    int size = 7 ;

    int minimum = findMinInArray(arr,size);
    cout<<"minimum number is:"<<minimum;
    return 0;
}