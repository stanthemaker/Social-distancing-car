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