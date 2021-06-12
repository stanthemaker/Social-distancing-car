#ifndef AMG_pixel_array_size
#define AMG_pixel_array_size 64
#endif
#include <Servo.h>
#include <Adafruit_AMG88xx.h>
#include "AMG.h"
#include "hc-sro4_self.h"
#define servo_pin 9
Adafruit_AMG88xx AMG;
Servo iservo;
long distance = 0;
// float pixels[AMG_pixel_array_size];
// long person [2][2];  
void setup(){
    Serial.begin(9600);
    HC_sro4_init();
    // AMG.begin();
    iservo.attach(servo_pin); //support only on 9 & 10
    iservo.write(15);
    delay(1000);
}

void loop(){
    for (int i = 15; i<= 165 ;i++){
        iservo.write(i);
        delay(30);
        distance = get_distance();
        Serial.print("angle = ");
        Serial.print(i);
        Serial.print(", distance = ");
        Serial.println(distance);
    }
    for (int i = 165; i >= 15 ;i--){
        iservo.write(i);
        delay(30);
        distance = get_distance();
        Serial.print("angle = ");
        Serial.print(i);
        Serial.print(", distance = ");
        Serial.println(distance);
    }
    delay(2000);
}
