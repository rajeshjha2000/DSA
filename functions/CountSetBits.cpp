#include <iostream>
using namespace std;

int countSetBits(int n){
    int count =0;

    while (n > 0)
    {
        int bit = (n & 1);
        if (bit ==1){
            count++ ;
            n = n >> 1;
        }
        return count;
    }
    
}

int main(){
    int n;
    cin>>n;
    int setBitCount = countSetBits(n);
    cout<<setBitCount<<endl;
}