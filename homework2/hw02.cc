#include <cstdio>
#include "mandelbrot.h" 


int main(int argc, char** argv) {
    
    float x=0.0, y=0.0;
    float a=-2.0, b=-1.5;
    printf("new");

    for(int i=0; i<80; i++){
        
        for(int j=0; j<80; j++){
            x=0.0;
            y=0.0;
            for(int k=0; k<1000; k++){
                x=getX(x, y, a);
                y=getY(x, y, b);
                if (setFlag(x, y)){
                    printf("*");
                    break;
                }
                else if(k==999){
                    printf(" ");
                }
            }
            b+=0.025;
        }
        b=-1.5;
        a+=0.0375;
        printf("\n");
    }

}