GXX = g++
CFLAGS = -Wall -Werror -O2

all: hw07

hw07: hw07.o image.o
	$(GXX) $(CFLAGS) -o hw07 hw07.o image.o

hw07.o: hw07.cc image.h
	$(GXX) $(CFLAGS) -c hw07.cc

image.o: image.cc image.h
	$(GXX) $(CFLAGS) -c image.cc

clean:
	rm -f *.o