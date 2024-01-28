.PHONY: all clean
.DEFAULT: all

all: vector.o

clean:
	rm vector.o

vector.o: vector.c vector.h
	gcc $(FLAGS) -c vector.c -o vector.o
