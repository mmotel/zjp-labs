all: build
	mpirun -np 5 a.out 100

build: main.c
	mpicc -Wall main.c -lrt

clear: a.out
	rm -f *.out
