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

	int np, rank;
	MPI_Status status;
	
  int buffer[1];

  int j, sum = 0;
  int size = atoi(argv[1]);

  int *tab = (int*) malloc( size * sizeof(int) );

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &np);

  if(rank == 0){
//    printf("jestem %d i czekam\n", rank);
//    printf("size: %d , procs: %d\n", size, np);
    
    for(j = 0; j < size; j++){
      tab[j] = 2;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);

    for(j=1; j < np; j++){
      MPI_Send(tab, size, MPI_INT, j, 123,  MPI_COMM_WORLD);
    }

    for(j=1; j < np; j++){
      MPI_Recv(buffer, 1, MPI_INT, j, 124, MPI_COMM_WORLD, &status);
     // printf("suma z %d = %d\n", j, buffer[0]);
      sum += buffer[0];
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("time :  %.16f\n", timespecDiff(&end, &start));
    printf("finalSum = %d\n", sum);
  }
  else if(rank > 0){
    int i = rank;
    int begin = (i-1) * size / (np-1);
    int stop =  i * size / (np-1);

    MPI_Recv(tab, size, MPI_INT, 0, 123, MPI_COMM_WORLD, &status);

    clock_gettime(CLOCK_MONOTONIC, &start);

    for(j = begin ; j < stop; j++){
        sum += tab[j];
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("time%d:  %.16f\n", rank, timespecDiff(&end, &start));
    //printf("%d : < %d , %d ) sum = %d\n", rank, begin, stop, sum);

    buffer[0] = sum;
    MPI_Send(buffer, 1, MPI_INT, 0, 124, MPI_COMM_WORLD);

  }	
	free(tab); 
	MPI_Finalize(); 

  return 0;
}
