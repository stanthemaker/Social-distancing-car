#include <Adafruit_AMG88xx.h>

float* return_amg_pixel( float* pixels ){
    return (AMG.readPixels(pixels));
}