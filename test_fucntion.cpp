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
    int n=0;
    cout << "array size = "<<endl;
    cin >> n;
    int i =0;
    int * array;
    float avg = 0;
    array = new int [n];
    while (i< n){
        cin >> array [i];
        i++;
    }
    if ( avg = is_object1(array) ){
        cout << "avg = "<<avg <<endl;
    }
    else{
        cout << "false"<<endl;
    }
    delete [] array;
}
