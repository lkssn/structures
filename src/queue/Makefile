.PHONY: all clean
.DEFAULT: all

all: queue.o

clean:
	rm queue.o

queue.o: queue.c queue.h
	gcc $(FLAGS) -c queue.c queue.h -o queue.o
