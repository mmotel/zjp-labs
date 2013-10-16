all: build
	mpirun -np 4 a.out

build:
	mpicc -Wall main.c -lrt

clear:
	rm -f *.out
