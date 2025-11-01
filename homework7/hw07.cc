#include "image.h"
#include <iostream>

int main() {
    
    Image img("my_test.ppm");
    img += 50; // brighten the image
    img.writePPM("brightened.ppm");

}