#include <iostream>
#include <iomanip>
using namespace std;
float is_object1(int* arr){
    int num = 0;
    for (int i = 0; abs(arr[i]) <200 ;i++){
        cout << "arr[i] = "<< arr[i]<<endl;
        num ++;
    }
    cout << "num = "<<num <<endl;
    if (num <= 5){
        return false;
    }
    int avg =0;
    for (int i = 0;i<num;i++){
        avg += arr[i] / num ;
    }
    if (avg < 30 || avg > 150){
        return false;
    }
    return true;
}
int main(){
    int a = 0, b= 0 , c = 0;
    cout << a << b <<c <<endl;
}
