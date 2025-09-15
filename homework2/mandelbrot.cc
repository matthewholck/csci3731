#include "mandelbrot.h"

bool setFlag (float x, float y) {
    return ((x*x) + (y*y)) > 4.0;        
}

float getX (float x, float y, float a){
    return (x*x) - (y*y) + a;
}

float getY (float x, float y, float b){
    return 2*(x*y) + b;
}