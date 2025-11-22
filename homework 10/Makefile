GXX = g++
CFLAGS = -Wall -Werror -O2

all: hw10

hw10: hw10.o pattern.o
	$(GXX) $(CFLAGS) -o hw10 hw10.o pattern.o

hw10.o: hw10.cc pattern.h
	$(GXX) $(CFLAGS) -c hw10.cc

pattern.o: pattern.cc
	$(GXX) $(CFLAGS) -c pattern.cc

clean:
	rm -f *.o
