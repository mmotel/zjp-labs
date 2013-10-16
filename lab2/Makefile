all: build

build: main.c
	gcc -Wall -c main.c lib.c
	gcc -Wall main.o lib.o -lrt

clear: 
	rm -f *.out *.o
