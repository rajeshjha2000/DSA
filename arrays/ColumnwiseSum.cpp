#include <iostream>
using namespace std;

void columnWiseSum(int arr[][4], int row, int col){
    for (int i = 0; i < col; i++)
    { 
        int sum =0;
        for (int j = 0; j < row; j++)
        {
          sum = sum + arr[j][i];
            
        }
        cout<<"columnWise sum is :"<<sum<<endl;;
    }
    
}

int main(){
    int arr[3][4] ={ {4,7,12,8},
                     {50,60,70,80},
                      {9,10,11,12} };

 int row = 3;
 int col = 4;

      columnWiseSum(arr, row, col);
            return 0 ;           
                      }