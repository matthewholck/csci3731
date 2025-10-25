#include <cstdio>
#include <jpeglib.h>
#include <cstdlib>
#include "ppm_handler.h" 

int main(int argc, char** argv) {
    
    char* magic = new char[2]; 
    int x = 0;
    int y = 0;
    int pixel = 3;
    unsigned char* array = nullptr;
    
    readPPM(magic, &x, &y, &pixel, &array);
    toJPEG("test.jpg", array, x, y, 90);

    delete [] array;
    array = nullptr;

}