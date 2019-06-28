CC=g++

CFLAGS=-c -Wall -MMD -std=c++11

all: brain

brain: main.o matrix_gen.o mtx_multiplication.o responsecode.o
	 $(CC) main.o matrix_gen.o mtx_multiplication.o responsecode.o -o brain -lpthread

main.o: main.cpp
	 $(CC) $(CFLAGS) main.cpp

matrix_gen.o: matrix_gen.cpp
	 $(CC) $(CFLAGS) matrix_gen.cpp

mtx_multiplication.o: mtx_multiplication.cpp
	$(CC) $(CFLAGS) mtx_multiplication.cpp

responsecode.o: responsecode.cpp
	$(CC) $(CFLAGS) responsecode.cpp

clean:
	rm -rf *o brain
