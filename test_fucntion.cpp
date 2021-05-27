#include <iostream>
using namespace std;
float * return_array(float *array){
    int array_size = 0;
    for(int i = 0; array[i+1] == 0 ; i++){
        array_size ++;
    }
    cout << "array_size = "<< array_size<<endl;
    for(int i = 0;i<= array_size; i++){
        array[i] = i;
    }
    return array;
}
int main(){
    float pixel [10] {0};
    float* pixel_ptr;
    pixel_ptr = return_array(pixel);
    cout << "pixel = "<<endl;
    for (int i = 0;i < 10;i++){
        cout << pixel_ptr[i]<<endl;
    }
}