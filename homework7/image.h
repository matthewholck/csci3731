#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
private:
    int width;
    int height;
    int maxColor;
    unsigned char* pixels; 

public:
    Image();                                   
    Image(const std::string& filename);
    virtual ~Image();  // Destructor

    void readPPM(const std::string& filename); // not const because editing the class based on the read
    void writePPM(const std::string& filename) const; 

    Image& operator+=(int value); // Overload +=

};

#endif