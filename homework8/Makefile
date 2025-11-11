GXX = g++
CFLAGS = -Wall -Werror -O2

all: hw08

hw08: hw08.o exercise.o book.o
	$(GXX) $(CFLAGS) -o hw08 hw08.o exercise.o book.o

hw08.o: hw08.cc book.h
	$(GXX) $(CFLAGS) -c hw08.cc

exercise.o: exercise.cc exercise.h book.h
	$(GXX) $(CFLAGS) -c exercise.cc

book.o: book.cc book.h exercise.h
	$(GXX) $(CFLAGS) -c book.cc

clean:
	rm -f *.o
