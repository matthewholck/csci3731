#ifndef PPM_HANDLER
#define PPM_HANDLER

void readPPM (char* magic, int* x, int* y, int* pixel, unsigned char** array);
void writePPM (const char *filename, int x, int y, int pixel, const unsigned char *data);

#endif