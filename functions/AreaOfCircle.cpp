#include <iostream>
using namespace std;

float circle_area (float radius){
    float area = 3.14 * radius * radius ;
    return area ;
}

int main (){
    float radius;
    cin>>radius ;
    float result = circle_area( radius);
    cout<<"area of circle :"<<result<<endl;
    return 0;
}