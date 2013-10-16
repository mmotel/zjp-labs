all: build
	mpirun -np 6 a.out

build: main.c
	mpicc -Wall main.c

clear: a.out
	rm -f *.out
