#include <iostream>
using namespace std;

int main(){
    int arr[5]={2,4,8,10,12};
    int target = 11;
    int n =5;

    bool flag =0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i]==target)
        {
            flag=1;
            break;
        }
        
    }
    if (flag==1)
    {
        cout<<"target found";
    }
    else{
        cout<<"target not found";
    }
    
    
}