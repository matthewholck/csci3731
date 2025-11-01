#include "image.h"
#include <fstream>
#include <iostream>

Image::Image() : width(0), height(0), maxColor(255), pixels(nullptr) {}

Image::Image(const std::string& filename) : pixels(nullptr) {
    
    readPPM(filename);
    
}

Image::~Image() {
}

void Image::readPPM(const std::string& filename) {
    
    std::ifstream in(filename, std::ios::binary);
    std::string magic;
    in >> magic;

    in >> width >> height >> maxColor;
    in.ignore(1); // skip newline

    pixels = new unsigned char[width * height * 3];

    in.read(reinterpret_cast<char*>(pixels), width * height * 3);
    in.close();

}

void Image::writePPM(const std::string& filename) const {

    std::ofstream out(filename, std::ios::binary);

    out << "P6\n" << width << " " << height << "\n" << maxColor << "\n";
    out.write(reinterpret_cast<const char*>(pixels), width * height * 3);
    out.close();

}

Image& Image::operator+=(int value) {
    
    for (int i = 0; i < width * height * 3; ++i) {
        int temp = static_cast<int>(pixels[i]) + value;

        if(temp > 255) {
            temp = 255;
        }
        
        pixels[i] = static_cast<unsigned char>(temp);
    }
    
    return *this;
    
}
