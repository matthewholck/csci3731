#include <cstdio>
#include <jpeglib.h>
#include <cstdlib>
#include "ppm_handler.h" 

void readPPM(char* magic, int* x, int* y, int* pixel, unsigned char** array) {
    
    FILE* fp = fopen("my_test.ppm", "rb");
    fscanf(fp, "%s %d %d %d", magic, x, y, pixel);
    fgetc(fp); // consume the new line

    *array = new unsigned char[(*x)*(*y)*3];
    
    fread(*array, sizeof(unsigned char), (*x)*(*y)*3, fp);
    fclose(fp);

}

void writePPM(const char *filename, int x, int y, int pixel, const unsigned char *data) {
    FILE *fp = fopen(filename, "wb"); 

    fprintf(fp, "P6\n%d %d\n%d\n", x, y, pixel);
    fwrite(data, sizeof(unsigned char), x * y * 3, fp);
    fclose(fp);
}

void toJPEG(const char *jpeg_filename, unsigned char *ppm_data, int x, int y, int quality) {

    FILE *jpeg = fopen(jpeg_filename, "wb");
    if (!jpeg) {
        perror("Cannot open output JPEG file");
        delete[] ppm_data;
        return;
    }

    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, jpeg);

    cinfo.image_width = x;
    cinfo.image_height = y;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality, TRUE);

    jpeg_start_compress(&cinfo, TRUE);

    JSAMPROW row_pointer[1];
    int row_stride = x * 3;

    while (cinfo.next_scanline < cinfo.image_height) {
        
        row_pointer[0] = &ppm_data[cinfo.next_scanline * row_stride];
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
        
    }

    jpeg_finish_compress(&cinfo);
    fclose(jpeg);
    jpeg_destroy_compress(&cinfo);

}