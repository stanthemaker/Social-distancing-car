#include <Adafruit_AMG88xx.h>
extern Adafruit_AMG88xx amg;
void AMG_init(){
    bool status = amg.begin();
    if (!status) {
        Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
        while (1);
    }
}

void amg_get_pixel( float* pixels ){
    amg.readPixels(pixels);
    Serial.print("[");
    for(int i=1; i<=AMG88xx_PIXEL_ARRAY_SIZE; i++){
      Serial.print(pixels[i-1]);
      Serial.print(", ");
      if( i%8 == 0 ) Serial.println();
    }
    Serial.println("]");
}
