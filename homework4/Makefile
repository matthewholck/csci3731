GXX = g++
CFLAGS = -Wall -Werror -O2

all: hw04

ppm_handler.o: ppm_handler.cc ppm_handler.h
	$(GXX) -c $(CFLAGS) ppm_handler.cc

hw04.o: hw04.cc ppm_handler.h
	$(GXX) -c $(CFLAGS) hw04.cc

hw04: hw04.o ppm_handler.o
	$(GXX) -o hw04 hw04.o ppm_handler.o

clean:
	rm -f *.o