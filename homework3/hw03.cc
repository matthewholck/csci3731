#include <cstdio>
#include "mandelbrot.h" 


int main(int argc, char** argv) {

    FILE* fp = fopen("mandelbrot.txt", "w");
    
    float x=0.0, y=0.0;
    float a=-2.0, b=-1.5;

    for(int i=0; i<80; i++){
        
        for(int j=0; j<80; j++){
            x=0.0;
            y=0.0;
            if(isInSet(x, y, a, b)){
                fprintf(fp, "*");
            }
            else {
                fprintf(fp, " ");
            }
            b+=0.025;
        }
        b=-1.5;
        a+=0.0375;
        fprintf(fp, "\n");
    }
    fclose(fp);
}