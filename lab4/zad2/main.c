#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mpi.h"

double timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  double diff = (((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec));
  return diff / 1000000000;
}

int main(int argc, char **argv)
{
  struct timespec start, end;
  int np, rank, i, wynik, suma = 0;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int size = atoi(argv[1]);
  int *tab = (int*) malloc( sizeof(int) * size );

  clock_gettime(CLOCK_MONOTONIC, &start);
 
  if(rank == 0){ 
    for(i=0; i < size; i++){
      srand(time(0));
      tab[i] = rand() % 1000;
    }
  }

  MPI_Bcast(tab, size, MPI_INT, 0, MPI_COMM_WORLD);

  for(i = rank * size / np; i < (rank+1) * size / np; i++){
    suma += tab[i];
  }

  MPI_Reduce(&suma,&wynik,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

  clock_gettime(CLOCK_MONOTONIC, &end);

  printf("czas%d: %.16f\n", rank, timespecDiff(&end, &start));

  if(rank == 0){
    printf("SUMA: %d\n", wynik);
  }

  MPI_Finalize(); 

  return 0;
}
