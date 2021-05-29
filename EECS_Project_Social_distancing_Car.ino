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
float pixels[AMG_pixel_array_size];
void setup(){
    Serial.begin(9600);
    AMG.begin();
    iservo.attach(servo_pin); //support only on 9 & 10
    iservo.writeMicroseconds(1000); // set servo to the left
}

void loop(){
    for (int i = 0; i<= 180 ;i++){
        iservo.write(i);
  
    }
}
