#include <Adafruit_AMG88xx.h>
extern Adafruit_AMG88xx AMG;
float* return_amg_pixel( float* pixels ){
    AMG.readPixels(pixels);
    return NULL;
}
