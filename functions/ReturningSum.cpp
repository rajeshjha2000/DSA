#include <iostream>
using namespace std;

int sum (int a, int b, int c){
    int answer = a + b + c;
    return answer;

}

int main (){
    
    int result = sum(49, 54, 55);
     cout<<"sum of these three numbers :"<< result << endl ;
     return 0;
}