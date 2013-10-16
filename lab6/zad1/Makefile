all: build

build: main.c
	gcc -Wall -fopenmp main.c -o mainp -lm -lrt
	gcc -Wall main.c -o mains -lm -lrt
clear:
	rm -f *.out *.o
