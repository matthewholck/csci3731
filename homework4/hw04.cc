#include <cstdio>
#include "ppm_handler.h" 

int main(int argc, char** argv) {
    
    char* magic = new char[2]; 
    int x = 0;
    int y = 0;
    int pixel = 0;
    unsigned char* array = nullptr;
    
    readPPM(magic, &x, &y, &pixel, &array);
    writePPM("copy_of_my_test.ppm", x, y, pixel, array);

    delete [] array;
    array = nullptr;

}