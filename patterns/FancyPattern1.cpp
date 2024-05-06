#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int row= 0; row < n; row++)
    {
        int totalCol = row+1;
        for (int col = 0; col < totalCol; col++)
        {
            if (col==totalCol-1)
            {
                cout<<totalCol;
            }
            else{
                cout<<totalCol<<"*";
            }
        }
        cout<<endl;
        
    }
    
}