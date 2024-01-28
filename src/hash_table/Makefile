.PHONY: all clean
.DEFAULT: all

all: hash_table.o

clean:
	rm hash_table.o

hash_table.o: hash_table.c hash_table.h
	gcc $(FLAGS) -c hash_table.c -o hash_table.o
