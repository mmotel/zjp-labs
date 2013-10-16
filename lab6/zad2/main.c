#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){

  int size = atoi(argv[1]);
  int i,j,k;
  //declare matrixes
  int **M = (int**) malloc( size * sizeof(int*) );
  int **N = (int**) malloc( size * sizeof(int*) );
  int **W = (int**) malloc( size * sizeof(int*) );

  #pragma omp parallel for private(i), shared(M), shared(N), shared(W)
  for(i=0; i < size; i++){
    M[i] = (int*) malloc( size * sizeof(int) );
    N[i] = (int*) malloc( size * sizeof(int) );
    W[i] = (int*) malloc( size * sizeof(int) );
  }

  srand( 151013 );

  //fillup matrixes with data
  #pragma omp parallel for private(i), shared(M), shared(N), shared(W)
  for(i = 0; i < size; i++){
    #pragma omp parallel for private(j), shared(M), shared(N), shared(W)
    for(j=0; j < size; j++){
      M[i][j] = rand() % 10; //1;
      N[i][j] = rand() % 10; //1;
      W[i][j] = 0;
    }
  }

  //compute matrix product
  #pragma omp parallel for private(i), shared(W)
  for(i = 0; i < size; i++){
    #pragma omp parallel for private(j), shared(W)
    for(j = 0; j < size; j++){
      int comp_w = 0;
      #pragma omp parallel for private(k), reduction(+:comp_w)
      for(k = 0; k < size; k++){
          comp_w += M[i][k] * N[k][j];
      }
      W[i][j] = comp_w;
    }
  }

  //print computed matrix product
  for(i = 0; i < size; i++){
    for(j = 0; j < size; j++){
      printf("[(%d,%d)= %d ] ", i,j,W[i][j]);
    }
    printf("\n");
  }

  //free allocated space
  free(M);
  free(N);
  free(W);
 
  return 0;
}
