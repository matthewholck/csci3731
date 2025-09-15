GXX = g++
CFLAGS = -Wall -Werror -O2

all: hw02

mandelbrot.o: mandelbrot.cc mandelbrot.h
	$(GXX) -c $(CFLAGS) mandelbrot.cc

hw02.o: hw02.cc mandelbrot.h
	$(GXX) -c $(CFLAGS) hw02.cc

hw02: hw02.o mandelbrot.o
	$(GXX) -o hw02 hw02.o mandelbrot.o

clean:
	rm -f *.o