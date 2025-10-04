#include <cstdio>
#include "ppm_handler.h" 
#include "array_handler.h"

int main(int argc, char** argv) {
    
    int x = 80;
    int y = 80;
    float a = 0.0;
    float b = 0.0;
    int pixel = 255;
    unsigned char** array = create2DArray(x, y);
    
    fillMandelArray(array, x, y, a, b);
    writePPM("mandelbrot.ppm", x, y, pixel, *array);

    delete[] *array;
    delete [] array;
    array = nullptr;

}