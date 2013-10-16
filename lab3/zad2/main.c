#include <stdio.h>
#include <stdlib.h>

#include "mpi.h"

int main(int argc, char **argv)
{
	int np, rank;
	MPI_Status status;
	
  int buffer[1];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &np);

  if(rank == 0){
    printf("jestem %d i czekam\n", rank);
    MPI_Recv(buffer, 1, MPI_INT, 1 , 124 , MPI_COMM_WORLD, &status);
    printf("%d. odebrałem: %d\n", rank, buffer[0]);
  }
  else if(rank > 0){
    buffer[0] = 13;
    printf("jestem %d i wysyłam: %d \n", rank, buffer[0]);
    MPI_Send(buffer, 1, MPI_INT, 0, 124, MPI_COMM_WORLD);
  }	
	MPI_Finalize(); 

  return 0;
}
