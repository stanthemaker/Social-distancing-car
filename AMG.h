#include <Adafruit_AMG88xx.h>
#define arraysize 121
extern Adafruit_AMG88xx amg;
extern float temp[];
void AMG_init(){
    bool status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
}

float amg_get_temp( float* pixels ){
    amg.readPixels(pixels);
    float center_temp = (pixels[27] + pixels[28] + pixels[35] + pixels[36])/4 ;
    return center_temp;  
    // Serial.println(center_temp/2);
    // double avg = 0;
    // for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
    //     avg += pixels[i] / 60 ;
    // }
//     Serial.print("[");
//     for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
//       Serial.print(pixels[i-1]);
//       Serial.print(", ");
//       if( i%8 == 0 ) Serial.println();
//     }
//     Serial.println("]");
}
void print_picture_temp(){
    for (int i = 0;i < arraysize; i++){
        Serial.println(temp[i]);
    }
    Serial.println();
}
int get_peak(){
    int marker = 0;
    float max = 0;
    for (int i = 0; i < arraysize - 4 ; i++)
    {
        float avg = 0;
        for(int j = i; j< i+5; j++){
            avg += temp [j] /5 ;
        }
        if ( max <= avg ){
            max = avg; 
            marker = i ;
        }
    }
    return marker ; 
}
void get_angle_range(int angle_1, int angle_2){
    angle_1 = get_peak();
    for (int i = angle_1 ; i < angle_1 +5 ; i++){
        temp [i] = 0;
    }
    angle_2 = get_peak();
    Serial.println("angle 1 2 = ");
    Serial.println(angle_1);
    Serial.println(angle_2);
    return ;
}
