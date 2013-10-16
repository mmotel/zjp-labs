#include <stdio.h>
#include <stdlib.h>

#include "mpi.h"

int main(int argc, char **argv)
{
  int np, rank, i, wynik, suma = 0;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int size = atoi(argv[1]);

  int *tab = (int*) malloc( sizeof(int) * size );
  
  for(i=0; i < size; i++){
    tab[i] = /*1;*/ rand() % 100;
  }
  
  for(i = rank * size / np; i < (rank+1) * size / np; i++){
    suma += tab[i];
  }

  MPI_Reduce(&suma,&wynik,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

  if(rank == 0){
    printf("SUMA: %d\n", wynik);
  }

  MPI_Finalize(); 

  return 0;
}
