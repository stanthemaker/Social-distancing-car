#ifndef AMG_pixel_array_size
#define AMG_pixel_array_size 64
#endif
#include <Servo.h>
#include <Adafruit_AMG88xx.h>
#include "AMG.h"
#include "hc-sro4_self.h"
#define servo_pin 9
Adafruit_AMG88xx amg;
Servo iservo;
long distance = 0;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

// long person [2][2];  
void setup(){
    Serial.begin(9600);
    HC_sro4_init();
    AMG_init();
    iservo.attach(servo_pin); //support only on 9 & 10
    iservo.write(15);
    delay(1000);
}

void loop(){
    for (int i = 15; i<= 165 ;i++){
        iservo.write(i);
        distance = get_distance(i);
        amg_get_pixel(pixels);
        delay(30);
    }
    for (int i = 165; i >= 15 ;i--){
        iservo.write(i);
        distance = get_distance(i);
        amg_get_pixel(pixels);
        delay(30);
    }
    delay(1000);
}
