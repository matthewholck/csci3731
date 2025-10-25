GXX = g++
CFLAGS = -Wall -Werror -O2

all: hw06

ppm_handler.o: ppm_handler.cc ppm_handler.h
	$(GXX) -c $(CFLAGS) ppm_handler.cc

hw06.o: hw06.cc ppm_handler.h
	$(GXX) -c $(CFLAGS) hw06.cc

hw06: hw06.o ppm_handler.o
	$(GXX) -o hw06 hw06.o ppm_handler.o -ljpeg

clean:
	rm -f *.o