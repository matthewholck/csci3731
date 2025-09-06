#include <cstdio>
#include <math.h>

float getX (float x, float y, float a){
    return (x*x) - (y*y) + a;
}

float getY (float x, float y, float b){
    return 2*(x*y) + b;
}

int main(int argc, char** argv) {
    
    float x=0.0, y=0.0;
    float a=0.1, b=0.2;

    for(int i=0; i<1000000; i++){
        if(isinf(getX(x, y, a)) || isinf(getY(getX(x, y, b), y, b))) {
            printf("%d", i);
            break;
        }
        x = getX(x, y, a);
        y = getY(x, y, b);
    }

    printf("X: %f, Y: %f\n", x, y);
}