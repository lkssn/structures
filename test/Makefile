.PHONY: all clean run
.DEFAULT: all

all: test_vector.exe

clean:
	rm test_vector.exe

run: all
#	./test_vector.exe
	./test_vector.exe

test_vector.exe: test_vector.c ../src/vector/vector.h ../src/vector/vector.o
	gcc $(FLAGS) test_vector.c ../src/vector/vector.o -I../src/vector -L../src/vector  -o test_vector.exe

# test_vector.exe
