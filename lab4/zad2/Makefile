all: build
	mpirun -np 8 a.out 32

build:
	mpicc -Wall main.c -lrt

clear:
	rm -f *.out
