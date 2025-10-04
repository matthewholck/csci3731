GXX = g++
CFLAGS = -Wall -Werror -O2

all: hw05

mandelbrot.o: mandelbrot.cc mandelbrot.h
	$(GXX) -c $(CFLAGS) mandelbrot.cc

ppm_handler.o: ppm_handler.cc ppm_handler.h
	$(GXX) -c $(CFLAGS) ppm_handler.cc

array_handler.o: array_handler.cc array_handler.h mandelbrot.h
	$(GXX) -c $(CFLAGS) array_handler.cc

hw05.o: hw05.cc ppm_handler.h mandelbrot.h array_handler.h
	$(GXX) -c $(CFLAGS) hw05.cc

hw05: hw05.o mandelbrot.o ppm_handler.o array_handler.o
	$(GXX) -o hw05 hw05.o mandelbrot.o ppm_handler.o array_handler.o

clean:
	rm -f *.o