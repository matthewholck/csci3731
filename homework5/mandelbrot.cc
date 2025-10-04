#include "mandelbrot.h"

void getXY (float* x_ptr, float* y_ptr, float a, float b){

    float x = *x_ptr;
    float y = *y_ptr;
    
    *x_ptr = (x*x) - (y*y) + a;
    *y_ptr = 2*(x*y) + b;
    
}

bool isInSet (float a, float b) {

    float x = 0.0;
    float y = 0.0;
    
    for(int k=0; k<1000; k++){
        
        getXY(&x, &y, a, b);
        
        if (((x*x) + (y*y)) > 4.0){
            return true;
        }
        
    }
    
    return false;
    
}