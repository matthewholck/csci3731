#include <cstdio>
#include "array_handler.h"
#include "mandelbrot.h"


// Numerical Recipes trick
unsigned char** create2DArray(int x, int y) {

    unsigned char** array = new unsigned char*[y];
    *array = new unsigned char[x*y];

    for (int i = 1; i < y; i++) {
        array[i] = array[i-1] + x;
    }

    return array;
}

void fillMandelArray(unsigned char** array, int x, int y, float a, float b) {
    
    for (int j = 0; j < y; j++) {

        for (int i = 0; i < x; i++) {
            
            array[j][i] = 255 * ((int) isInSet(a, b));

            a+=0.0375;
            
        }
        b+=0.025;
        a=-2.0;
    }
}