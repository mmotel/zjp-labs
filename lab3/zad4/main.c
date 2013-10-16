#include <stdio.h>
#include <stdlib.h>

#include "mpi.h"

int main(int argc, char **argv)
{
	int np, rank;
	MPI_Status status;
	
  int buffer[1], buffer2[1];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &np);

  if(rank == 0){
    printf("jestem %d i czekam na liczbę: \n", rank);
    scanf("%d", &buffer[0]);
    MPI_Send(buffer, 1, MPI_INT, 1, 124,  MPI_COMM_WORLD);
    MPI_Recv(buffer2, 1, MPI_INT, np - 1, 124, MPI_COMM_WORLD, &status);
    printf("%d. Odebrałem: %d\n", rank, buffer2[0]);
  }
  else if(rank > 0 ){
    int nextRec = rank + 1;
    if( nextRec == np){
      nextRec = 0;
    }
    MPI_Recv(buffer, 1, MPI_INT, rank - 1, 124, MPI_COMM_WORLD, &status);
    printf("%d. Odebrałem: %d\n", rank, buffer[0]); 
    MPI_Send(buffer, 1, MPI_INT, nextRec, 124, MPI_COMM_WORLD);

  }
	MPI_Finalize(); 

  return 0;
}
