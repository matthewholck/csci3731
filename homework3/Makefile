GXX = g++
CFLAGS = -Wall -Werror -O2

all: hw03

mandelbrot.o: mandelbrot.cc mandelbrot.h
	$(GXX) -c $(CFLAGS) mandelbrot.cc

hw03.o: hw03.cc mandelbrot.h
	$(GXX) -c $(CFLAGS) hw03.cc

hw03: hw03.o mandelbrot.o
	$(GXX) -o hw03 hw03.o mandelbrot.o

clean:
	rm -f *.o