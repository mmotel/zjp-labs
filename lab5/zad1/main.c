#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mpi.h"

int main(int argc, char **argv)
{
  int np, rank;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int *tab, *tab2, *recvTab;
  int i;
  int recv1;


  if(rank == 0){
    tab = (int*) malloc( sizeof(int) * np);
    
    srand(time(0));
    for(i=0; i < np; i++){
      tab[i] = rand() % 100;
    }
    for(i=0; i < np; i++){
      printf("[ %d ] ", tab[i]);
    }
    printf("\n");
  }

  MPI_Scatter(tab, 1, MPI_INT, &recv1, 1, MPI_INT, 0, MPI_COMM_WORLD);

  if(rank == 0){
    free(tab);
  }  

  tab2= (int*) malloc( 4 * sizeof(int));

  srand(recv1);
  for(i=0; i < 4; i++){
    tab2[i] = rand() % 100;
  }

  if(rank == 0){
    recvTab = (int*) malloc( 4 * np * sizeof(int));
  }

  MPI_Gather(tab2, 4, MPI_INT, recvTab, 4, MPI_INT, 0, MPI_COMM_WORLD);

  if(rank == 0){
    for(i=0; i < 4 * np; i++){
      printf("[ %d ] ", recvTab[i]);
    }
    printf("\n");
  }

  free(tab2);
  
  if(rank == 0){
    free(recvTab);
  }


  MPI_Finalize(); 

  return 0;
}
