all: build
	mpirun -np 8 a.out 32

build:
	mpicc -Wall main.c

clear:
	rm -f *.out
