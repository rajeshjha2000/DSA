#include <iostream>
using namespace std;

void diagonalWiseSum(int arr[][4], int row){
       int sum =0;
    for (int i = 0; i < row; i++)
    { 
      sum = sum + arr[i][i];
    }
    cout<<"diagonalWise sum is :"<<sum<<endl;
}

int main(){
    int arr[4][4] ={ {4,7,12,8},
                     {50,60,70,80},
                      {9,10,11,12},
                      {10,10,20,30} };

 int row = 4;

      diagonalWiseSum(arr, row);
            return 0 ;           
                      }