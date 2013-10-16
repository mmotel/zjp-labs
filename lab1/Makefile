all: build

comp: main.c lib.c
	gcc -Wall -c main.c lib.c

build: comp
	gcc -Wall main.o lib.o

clean:
	rm -f *.o *.~ a.out 

run:
	./a.out
