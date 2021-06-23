#ifndef AMG_pixel_array_size
#define AMG_pixel_array_size 64
#endif
#include <Servo.h>
#include <Adafruit_AMG88xx.h>
#include "AMG.h"
#include "hc-sro4_self.h"
#include "never_gonna.h"
#define servo_pin 9
#define arraysize 121
#define start_angle 30
#define end_angle 150
Adafruit_AMG88xx amg;
Servo iservo;
long distance = 0;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];
float picture [arraysize] = {};
Person person [2];
extern int nevergonna[];

void setup(){
    Serial.begin(9600);
    HC_sro4_init();
    AMG_init();
    iservo.attach(servo_pin); //support only on 9 & 10
    iservo.write(30);
    Serial.println(sizeof(nevergonna));
    play_music(nevergonna, 114);
    delay(1000);
}

void loop(){
    // std::fill (picture, picture + arraysize, 0);
    for (int i = start_angle; i<= end_angle ;i++){
        iservo.write(i);
        // Serial.print("angle = ");
        // Serial.print(i);
        picture [i - start_angle] = get_distance()/2 ;
        // amg_get_pixel(pixels);
        delay(30);
    }
    for (int i = end_angle; i >= start_angle ;i--){
        iservo.write(i);
        picture [i - start_angle] += get_distance()/2 ; 
        // amg_get_pixel(pixels);
        delay(30);
    }
    preprocess();
    print_picture();
    object_detection(person);
    Serial.print("2 person = ");

    for (int i = 0 ;i <2 ; i++){
        Serial.println(person[i].distance);
        Serial.print("angle = ");
        Serial.print(person[i].left_angle);
        Serial.print(" ");
        Serial.println(person[i].right_angle);
        Serial.println(" ");
    }
    
    delay(1000);
}
