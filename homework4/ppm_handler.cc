#include <cstdio>
#include "ppm_handler.h" 

void readPPM(char* magic, int* x, int* y, int* pixel, unsigned char** array) {
    
    FILE* fp = fopen("my_test.ppm", "rb");
    fscanf(fp, "%s %d %d %d", magic, x, y, pixel);
    fgetc(fp); // consume the new line

    *array = new unsigned char[(*x)*(*y)];
    
    fread(*array, sizeof(unsigned char), (*x)*(*y), fp);
    fclose(fp);

}

void writePPM(const char *filename, int x, int y, int pixel, const unsigned char *data) {
    FILE *fp = fopen(filename, "wb"); 

    fprintf(fp, "P6\n%d %d\n%d\n", x, y, pixel);
    fwrite(data, sizeof(unsigned char), x * y, fp);
    fclose(fp);
}