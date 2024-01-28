.PHONY: all clean
.DEFAULT: all

all: search_tree.o

clean:
	rm search_tree.o

search_tree.o: search_tree.c search_tree.h
	gcc $(FLAGS) -c search_tree.c search_tree.h -o search_tree.o
